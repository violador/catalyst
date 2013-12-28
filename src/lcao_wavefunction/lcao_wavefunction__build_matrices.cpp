#include "lcao_wavefunction.hpp"
//
//
//
void lcao_wavefunction::build_matrices(array &type,
                                       array &x,
                                       array &y,
                                       array &z,
                                       const unsigned int given_theory_level)
{
    global_log::file.write_debug_msg("lcao_wavefunction::build_matrices()");
    init_matrices(type.array::size_of_row());
    hamiltonian_matrix_ready = false;
//
//  (1) To allocate memory for the Core-Hamiltonian (H) matrix, h_matrix.
//  (2) To build up the overlap (S) matrix, s_matrix.
//  (3) To build up the kinetic (T) matrix, t_matrix.
//  (4) To build up the one electron Coulomb repulsion (V), v_matrix1.
//  (5) To build up the two electron repulsion (V) array, v_matrix2.
//  (6) To build the Core_Hamiltonian matrix from t_matrix and v_matrix1.
    #pragma omp parallel sections num_threads(5)
    {
        #pragma omp section
        {
            h_matrix.array::create_array(type.array::size_of_row(), 
                                         type.array::size_of_row());       // (1)
            h_matrix.array::set_name("Core-Hamiltonian matrix");
        }
        #pragma omp section
        {
            global_log::file.write_debug_msg("lcao_wavefunction::build_matrices(): ", 
                                             "Invoking lcao_wavefunction::build_overlap_matrix()...");
            build_overlap_matrix(s_matrix,
                                 type,
                                 x,
                                 y,
                                 z,
                                 given_theory_level);                      // (2)
        }
        #pragma omp section
        {
            global_log::file.write_debug_msg("lcao_wavefunction::build_matrices(): ", 
                                             "Invoking lcao_wavefunction::build_kinetic_matrix()...");
            build_kinetic_matrix(t_matrix,
                                 type,
                                 x,
                                 y,
                                 z,
                                 given_theory_level);                      // (3)
        }
        #pragma omp section
        {
            global_log::file.write_debug_msg("lcao_wavefunction::build_matrices(): ", 
                                             "Invoking lcao_wavefunction::build_repulsion_matrix_1()...");
            build_repulsion_matrix_1(v_matrix1,
                                     type,
                                     x,
                                     y,
                                     z,
                                     given_theory_level);                  // (4)
        }
        #pragma omp section
        {
            global_log::file.write_debug_msg("lcao_wavefunction::build_matrices(): ", 
                                             "Invoking lcao_wavefunction::build_repulsion_matrix_2()...");
            build_repulsion_matrix_2(v_matrix2,
                                     type,
                                     x,
                                     y,
                                     z,
                                     given_theory_level);                  // (5)
        }
    }
//
    h_matrix += t_matrix;  // (6)
    h_matrix += v_matrix1; // (6)
    hamiltonian_matrix_ready = true;
//
    switch(config -> state_of(option::temp_files_usage))
    {
        case true:
        #pragma omp parallel sections num_threads(4)
        {
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
                v_matrix1.array::save();
            }
            #pragma omp section
            {
                h_matrix.array::save();
            }
        }
        break;
    }
    switch(config -> state_of(option::debug_mode))
    {
        case true:
        s_matrix.array::write();
        t_matrix.array::write();
        v_matrix1.array::write();
        h_matrix.array::write();
        break;
    }
}
