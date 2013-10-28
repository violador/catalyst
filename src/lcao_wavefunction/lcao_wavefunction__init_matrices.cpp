//
//
//
inline void init_matrices(const unsigned int &given_size)
{
    global_log::file.write_debug_msg("lcao_wavefunction::init_matrices(): Init square matrices of ", 
                                     given_size,
                                     " size");
    #pragma omp parallel sections num_threads(4)
    {
        #pragma omp section
        {
            s_matrix.array::create_array(given_size, given_size);
            s_matrix.array::set_name("Overlap matrix");
        }
        #pragma omp section
        {
            t_matrix.array::create_array(given_size, given_size);
            s_matrix.array::set_name("Kinetic matrix");
        }
        #pragma omp section
        {
            v_matrix1.array::create_array(given_size, given_size);
            s_matrix.array::set_name("One electron repulsion matrix");
        }
        #pragma omp section
        {
            v_matrix2.array::create_array(given_size, 
                                          given_size,
                                          given_size,
                                          given_size);
            s_matrix.array::set_name("Two electron repulsion matrix");
        }
    }
};
