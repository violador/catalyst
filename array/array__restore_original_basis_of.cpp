#include "array.hpp"
//
//
//
void array::restore_original_basis_of(array &given_array)
{
//  (1) Backup the current array (a matrix transformation) in a temp one.
//  (2) Backup the given array (the matrix to be transformed) in a temp one.
//  (3) To invoke the BLAS dgemm routine to multiply the temp matrices.   
    gsl_matrix *temp_2d_array = gsl_matrix_calloc(sizeof_row, sizeof_column);
    gsl_matrix *temp_given_array = gsl_matrix_calloc(sizeof_row, sizeof_column);
    gsl_matrix_memcpy(temp_2d_array, user_2d_array);                             // (1)
    gsl_matrix_memcpy(temp_given_array, given_array.user_2d_array);              // (2)
    gsl_matrix_set_all(given_array.user_2d_array, 0.0);
    gsl_blas_dgemm(CblasNoTrans,
                   CblasNoTrans,
                   1.0,
                   temp_2d_array,
                   temp_given_array,
                   1.0,
                   given_array.user_2d_array);                                   // (3)
    gsl_matrix_free(temp_2d_array);
    gsl_matrix_free(temp_given_array);
}
