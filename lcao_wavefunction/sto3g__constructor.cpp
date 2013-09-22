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
            h_matrix.create_array(number_of_atoms, number_of_atoms); // (1)
            h_matrix.set_name("Core-Hamiltonian matrix");
        }
        #pragma omp section
        {
            build_overlap_matrix();                                  // (2)
        }
        #pragma omp section
        {
            build_kinetic_matrix();                                  // (3)
        }
        #pragma omp section
        {
            build_repulsion_matrix();                                // (4)
        }
        #pragma omp section
        {
            two_electrons_repulsion();                               // (5)
        }
    }
    h_matrix += t_matrix;
    h_matrix += v_matrix;
    //t_matrix.add_to(h_matrix);        // (6)
    //v_matrix.add_to(h_matrix);        // (6)
    if(runtime_setup.settings::state_of(DEBUG_MODE))
    {
        //runtime_setup.settings::log("\n@lcao_wavefunction::sto3g::sto3g(): Follows the calculated T and V matrices");
        //runtime_setup.settings::log(t_matrix);
        //runtime_setup.settings::log(v_matrix);
        //runtime_setup.settings::log("\n@lcao_wavefunction::sto3g::sto3g(): Invoking algorithm::scf::init_scf()");
    }
    //runtime_setup.settings::log(s_matrix);
    //runtime_setup.settings::log(h_matrix);
    //runtime_setup.settings::log("\n- Task ", task_number, " > STO-3G level of theory > SCF algorithm\n");
//
    //ab_initio_calculation.algorithm::scf::init_scf(h_matrix, s_matrix, two_electron_terms, runtime_setup); // (7)
}
