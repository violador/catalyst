//
//
//
inline void start_scf_iterations(array &type,
                                 array &x,
                                 array &y,
                                 array &z,
                                 const unsigned int &given_theory_level)
{
    #pragma omp parallel sections num_threads(3)
    {
        #pragma omp section
        {
            s_matrix.array::create_array(type.array::size_of_row(), type.array::size_of_row());
            build_overlap_matrix(s_matrix,
                                 type,
                                 x,
                                 y,
                                 z,
                                 given_theory_level);
        }
        #pragma omp section
        {
            h_matrix.array::create_array(type.array::size_of_row(), type.array::size_of_row());
            build_hamiltonian_matrix(h_matrix,
                                     type,
                                     x,
                                     y,
                                     z,
                                     given_theory_level);
        }
        #pragma omp section
        {
            v_matrix2.array::create_array(type.array::size_of_row(), 
                                          type.array::size_of_row(),
                                          type.array::size_of_row(),
                                          type.array::size_of_row());
            build_repulsion_matrix_2(v_matrix2,
                                     type,
                                     x,
                                     y,
                                     z,
                                     given_theory_level);
        }
    }
    iterative_routine.algorithm::scf::start_iterations(h_matrix, s_matrix, v_matrix2);
    f_matrix = iterative_routine.algorithm::scf::get_fock_matrix();
    p_matrix = iterative_routine.algorithm::scf::get_density_matrix();
    wavefunction = iterative_routine.algorithm::scf::get_wavefunction();
};
