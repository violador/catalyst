#include "array.hpp"
//
//
//
void array::create_array(const unsigned int local_row_size,
                         const unsigned int local_column_size,
                         const unsigned int local_1st_layer_size,
                         const unsigned int local_2nd_layer_size)
{
    if((local_row_size > 0) and (local_column_size == 0))
    {
        #pragma omp parallel sections num_threads(2)
        {
            #pragma omp section
            {
                init_properties(local_row_size);
            }
            #pragma omp section
            {
                user_1d_array = gsl_vector_calloc(local_row_size);
            }
        }
    }
    else if((local_row_size > 0) and (local_column_size > 0) and (local_1st_layer_size == 0))
    {
        #pragma omp parallel sections num_threads(2)
        {
            #pragma omp section
            {
                init_properties(local_row_size, local_column_size);
            }
            #pragma omp section
            {
                user_2d_array = gsl_matrix_calloc(local_row_size, local_column_size);
            }
        }
    }
    else if((local_row_size > 0) and (local_column_size > 0) and (local_1st_layer_size > 0) and (local_2nd_layer_size == 0))
    {
        #pragma omp parallel sections num_threads(2)
        {
            #pragma omp section
            {
                init_properties(local_row_size, local_column_size, local_1st_layer_size);
            }
            #pragma omp section
            {
                init_3d_array(local_row_size, local_column_size, local_1st_layer_size);
            }
        }
    }
    else
    {
        #pragma omp parallel sections num_threads(2)
        {
            #pragma omp section
            {
                init_properties(local_row_size, local_column_size, local_1st_layer_size, local_2nd_layer_size);
            }
            #pragma omp section
            {
                init_4d_array(local_row_size, local_column_size, local_1st_layer_size, local_2nd_layer_size);
            }
        }
    }    
}
