#include "array.hpp"
//
//
//
bool array::is_negative()
{
    bool aux;
    #pragma omp parallel sections num_threads(4)
    {
        #pragma omp section
        {
            switch(is_1d_array and (not deleted_array))
            {
                case true:
                aux = (bool) gsl_vector_isneg(&gsl_1d_view.vector);
                break;
            }
        }
        #pragma omp section
        {
            switch(is_2d_array and (not deleted_array))
            {
                case true:
                aux = (bool) gsl_matrix_isneg(&gsl_2d_view.matrix);
                break;
            }
        }
        #pragma omp section
        {
            switch(is_3d_array and (not deleted_array))
            {
                case true:
                aux = false;
                break;
            }
        }
        #pragma omp section
        {
            switch(is_4d_array and (not deleted_array))
            {
                case true:
                aux = false;
                break;
            }
        }
    }
    return aux;
} 
