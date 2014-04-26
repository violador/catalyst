#include "lcao_wavefunction.hpp"
//
//
//
void lcao_wavefunction::check_matrix_size(array &given_matrix, const unsigned int &given_size)
{
    #pragma omp parallel sections num_threads(2)
    {
        #pragma omp section
        {
            switch(given_matrix.array::size_of_column() > 0)
            {
                case true:
                switch((given_matrix.array::size_of_row() == given_size)
                       and (given_matrix.array::size_of_column() == given_size))
                {
                    case false: given_matrix.array::resize(given_size, given_size); break;
                    case  true: given_matrix.array::set_all(0.0); break;
                }
                break;
            }
        }
        #pragma omp section
        {
            switch(given_matrix.array::size_of_2nd_layer() > 0)
            {
                case true:
                switch((given_matrix.array::size_of_row() == given_size)
                       and (given_matrix.array::size_of_column() == given_size)
                       and (given_matrix.array::size_of_1st_layer() == given_size)
                       and (given_matrix.array::size_of_2nd_layer() == given_size))
                {
                    case false: given_matrix.array::resize(given_size,
                                                                 given_size,
                                                                 given_size,
                                                                 given_size); break;
                    case  true: given_matrix.array::set_all(0.0); break;
                }
                break;
            }
        }
    }
};
