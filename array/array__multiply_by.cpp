#include "array.hpp"
//
//
//
void array::multiply_by(array &given_array)
{
//  (1) To invoke the GSL gsl_vector_mul() member and multiply the current and given 1D arrays.
//  (2) To invoke the BLAS dgemv member and multiply the current and given 1D and 2D arrays.
//  (3) To invoke the BLAS dgemm member and multiply the current and given 2D arrays.
    if(is_1d_array && given_array.is_1d_array && (!is_const_array))
    {
        if(sizeof_row == given_array.sizeof_row)
        {
            gsl_vector_mul(user_1d_array, given_array.user_1d_array);             // (1)
        }
    }
    else if(given_array.is_2d_array && is_1d_array && (!is_const_array))
    {
        gsl_vector *temp_1d_array = gsl_vector_calloc(sizeof_row);
        gsl_vector_swap(user_1d_array, temp_1d_array);
//
        gsl_blas_dgemv(CblasNoTrans,
                       1.0,
                       given_array.user_2d_array,
                       temp_1d_array,
                       1.0,
                       user_1d_array);                                            // (2)
//
        gsl_vector_free(temp_1d_array);
    }
    else if(is_2d_array && given_array.is_2d_array && (!is_const_array))
    {
        gsl_matrix *temp_2d_array = gsl_matrix_calloc(sizeof_row, sizeof_column);
        gsl_matrix_swap(user_2d_array, temp_2d_array);
//
        gsl_blas_dgemm(CblasNoTrans,
                       CblasNoTrans,
                       1.0,
                       temp_2d_array,
                       given_array.user_2d_array,
                       1.0,
                       user_2d_array);                                            // (3)
//
        gsl_matrix_free(temp_2d_array);
    }
}
