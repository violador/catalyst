#include "array.hpp"
//
//
//
void array::delete_array()
{
    #pragma omp parallel sections num_threads(4)
    {
        #pragma omp section
        {
            if(is_1d_array)
            {
                gsl_vector_free(user_1d_array);
                deleted_array = true;
            }
        }
        #pragma omp section
        {
            if(is_2d_array)
            {
                gsl_matrix_free(user_2d_array);
                deleted_array = true;
            }
        }
        #pragma omp section
        {
            if(is_3d_array)
            {
                delete_3d_array();
                deleted_array = true;
            }
        }
        #pragma omp section
        {
            if(is_4d_array)
            {
                delete_4d_array();
                deleted_array = true;
            }
        }
    }
}
