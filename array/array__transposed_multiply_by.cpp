#include "array.hpp"
//
//
//
void array::transposed_multiply_by(array &given_array)
{
//  (1) To invoke the BLAS dgemm member to handle the transposition and then to multiply.
    if(is_2d_array && given_array.is_2d_array && (!is_const_array))
    {
        gsl_matrix *temp_2d_array = gsl_matrix_calloc(sizeof_row, sizeof_column);
        gsl_matrix_swap(user_2d_array, temp_2d_array);
//
        gsl_blas_dgemm(CblasTrans,
                       CblasNoTrans,
                       1.0,
                       temp_2d_array,
                       given_array.user_2d_array,
                       1.0,
                       user_2d_array);            // (1)
//
        gsl_matrix_free(temp_2d_array);
    }
}
