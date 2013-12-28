#include "lcao_wavefunction.hpp"
//
//
//
void lcao_wavefunction::build_hamiltonian_matrix(array &h_matrix,
                                                 array &type,
                                                 array &x,
                                                 array &y,
                                                 array &z,
                                                 const unsigned int given_theory_level)
{
//
    switch(h_matrix.array::check_if(IS_CONSTANT))
    {
        case false: 
        check_matrix_size(h_matrix, type.array::size_of_row()); 
        h_matrix.array::set_name("Core-Hamiltonian matrix");
        break;
    }
//
    hamiltonian_matrix_ready = false;
    #pragma omp parallel sections num_threads(2)
    {
        #pragma omp section
        {
            global_log::file.write_debug_msg("lcao_wavefunction::build_hamiltonian_matrix(): ", 
                                             "Invoking lcao_wavefunction::build_kinetic_matrix()...");
            t_matrix.array::create_array(type.array::size_of_row(), type.array::size_of_row());
            build_kinetic_matrix(t_matrix,
                                 type,
                                 x,
                                 y,
                                 z,
                                 given_theory_level);
        }
        #pragma omp section
        {
            global_log::file.write_debug_msg("lcao_wavefunction::build_hamiltonian_matrix(): ", 
                                             "Invoking lcao_wavefunction::build_repulsion_matrix_1()...");
            v_matrix1.array::create_array(type.array::size_of_row(), type.array::size_of_row());
            build_repulsion_matrix_1(v_matrix1,
                                     type,
                                     x,
                                     y,
                                     z,
                                     given_theory_level);
        }
    }
//
    h_matrix.array::set_all(0.0);
    h_matrix += t_matrix; 
    h_matrix += v_matrix1;
//
    #pragma omp parallel sections num_threads(4)
    {
        #pragma omp section
        {
            switch(config -> state_of(option::output_mode))
            {
                 case false: break;
                 case  true: h_matrix.array::write(); break;
            }
        }
        #pragma omp section
        {
            //t_matrix.array::delete_array();
        }
        #pragma omp section
        {
            //v_matrix1.array::delete_array();
        }
        #pragma omp section
        {
            hamiltonian_matrix_ready = true;
        }
    }
}
