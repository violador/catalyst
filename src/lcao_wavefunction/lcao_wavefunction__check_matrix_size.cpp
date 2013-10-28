#include "lcao_wavefunction.hpp"
//
//
//
void lcao_wavefunction::check_matrix_size(array &given_matrix, const unsigned int &dimension_size)
{
    #pragma omp parallel sections num_threads(2)
    {
        #pragma omp section
        {
            switch(given_matrix.array::size_of_column() > 0)
            {
                case true:
                switch((given_matrix.array::size_of_row() == dimension_size) 
                       and (given_matrix.array::size_of_column() == dimension_size))
                {
                    case false: given_matrix.array::resize_array(dimension_size, dimension_size); break;
                    case  true: break;
                }
                break;
            }
        }
        #pragma omp section
        {
            switch(given_matrix.array::size_of_2nd_layer() > 0)
            {
                case true:
                switch((given_matrix.array::size_of_row() == dimension_size) 
                       and (given_matrix.array::size_of_column() == dimension_size)
                       and (given_matrix.array::size_of_1st_layer() == dimension_size)
                       and (given_matrix.array::size_of_2nd_layer() == dimension_size))
                {
                    case false: given_matrix.array::resize_array(dimension_size, 
                                                                 dimension_size,
                                                                 dimension_size,
                                                                 dimension_size); break;
                    case  true: break;
                }
                break;
            }
        }
    }
};
