#include "sto3g.hpp"
//
//
//
lcao_wavefunction::sto3g::sto3g(unsigned int &total_atoms,
                                array  &position_x,
                                array  &position_y,
                                array  &position_z,
                                array  &atom_types,
                                settings &runtime_setup,
                                const unsigned int &given_task)
{
    number_of_atoms = total_atoms;
    x = &position_x;
    y = &position_y;
    z = &position_z;
    type = &atom_types; 
    task_number = given_task;
    config = &runtime_setup;
//  (1) To allocate memory for the Core-Hamiltonian (H) matrix, h_matrix.
//  (2) To build up the overlap (S) matrix, s_matrix.
//  (3) To build up the kinetic (T) matrix, t_matrix.
//  (4) To build up the one electron Coulomb repulsion (V), v_matrix.
//  (5) To build up the two electron repulsion (V) array, two_electron_terms.
//  (6) To build the Core_Hamiltonian matrix from t_matrix and v_matrix.
//  (7) To invoke the SCF routine to calculate the orbitals, energies, density matrix etc.
    #pragma omp parallel sections num_threads(5)
    {
        #pragma omp section
        {
            h_matrix.array::create_array(number_of_atoms, number_of_atoms); // (1)
            h_matrix.array::set_config(*config);
            h_matrix.array::set_name("Core-Hamiltonian matrix");
        }
        #pragma omp section
        {
            build_overlap_matrix();                                         // (2)
        }
        #pragma omp section
        {
            build_kinetic_matrix();                                         // (3)
        }
        #pragma omp section
        {
            build_repulsion_matrix();                                       // (4)
        }
        #pragma omp section
        {
            two_electrons_repulsion();                                      // (5)
        }
    }
    h_matrix += t_matrix; // (6)
    h_matrix += v_matrix; // (6)
    if(runtime_setup.settings::state_of(DEBUG_MODE))
    {
        global_log::file.write("@lcao_wavefunction::sto3g::sto3g():");
        t_matrix.array::report();
        v_matrix.array::report();
        global_log::file.write("@lcao_wavefunction::sto3g::sto3g(): Invoking algorithm::scf::init_scf()");
    }
    s_matrix.array::report();
    h_matrix.array::report();
    global_log::file.write("- Task ", task_number, " > STO-3G level of theory > SCF algorithm");
//
    global_log::file.write("@lcao_wavefunction::sto3g::sto3g(): Invoking algorithm::scf::init_scf()");
    //ab_initio_calculation.algorithm::scf::init_scf(h_matrix, s_matrix, two_electron_terms, runtime_setup); // (7)
}
