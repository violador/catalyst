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
    #pragma omp parallel sections num_threads(7)
    {
        #pragma omp section
        {
            number_of_atoms = total_atoms;
        }
        #pragma omp section
        {
            x = &position_x;
        }
        #pragma omp section
        {
            y = &position_y;
        }
        #pragma omp section
        {
            z = &position_z;
        }
        #pragma omp section
        {
            type = &atom_types; 
        }
        #pragma omp section
        {
            task_number = given_task;
        }
        #pragma omp section
        {
            config = &runtime_setup;
            if(runtime_setup.settings::state_of(DEBUG_MODE))
            {
                global_log::file.write("@lcao_wavefunction::sto3g::sto3g()");
                global_log::file.write("@lcao_wavefunction::sto3g::sto3g(): Init data for task ", given_task);
                global_log::file.write("@lcao_wavefunction::sto3g::sto3g(): Starting the S, T, V and H matrices calculations.");
            }
        }
    }
//
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
//
    #pragma omp parallel sections num_threads(5)
    {
        #pragma omp section
        {
            s_matrix.array::write();
            if(runtime_setup.settings::state_of(DEBUG_MODE))
            {
                global_log::file.write("@lcao_wavefunction::sto3g::sto3g()");
                t_matrix.array::write();
                v_matrix.array::write();
                global_log::file.write("@lcao_wavefunction::sto3g::sto3g(): Invoking algorithm::scf::init()");
            }
            h_matrix.array::write();
        }
        #pragma omp section
        {
            s_matrix.array::save();
        }
        #pragma omp section
        {
            t_matrix.array::save();
        }
        #pragma omp section
        {
            v_matrix.array::save();
        }
        #pragma omp section
        {
            h_matrix.array::save();
        }
    }
    global_log::file.write("- Task ", task_number, " > STO-3G level of theory > SCF algorithm");
//
    //ab_initio_calculation.algorithm::scf::init_scf(h_matrix, s_matrix, two_electron_terms, runtime_setup); // (7)
}
