#include "array.hpp"
//
//
//
void array::orthonormalize(array &given_array)
{
    if(is_const_array)
    {
        gsl_matrix *user_array_transposed = gsl_matrix_calloc(sizeof_row, sizeof_column);
        gsl_matrix_transpose_memcpy(user_array_transposed, user_2d_array);
        gsl_matrix *temp_given_array = gsl_matrix_calloc(sizeof_row, sizeof_column);
        gsl_matrix_swap(given_array.user_2d_array, temp_given_array);
        gsl_blas_dgemm(CblasNoTrans,
                       CblasNoTrans,
                       1.0,
                       user_array_transposed,
                       temp_given_array,
                       1.0,
                       given_array.user_2d_array);
        gsl_matrix_set_all(temp_given_array, 0.0);
        gsl_matrix_free(user_array_transposed);
        gsl_matrix_swap(given_array.user_2d_array, temp_given_array);
        gsl_blas_dgemm(CblasNoTrans,
                       CblasNoTrans,
                       1.0,
                       temp_given_array,
                       user_2d_array,
                       1.0,
                       given_array.user_2d_array);
        gsl_matrix_free(temp_given_array);
    }
    else
    {
        gsl_matrix *eigenvectors = gsl_matrix_calloc(sizeof_row, sizeof_column);
        gsl_vector *eigenvalues = gsl_vector_calloc(sizeof_row);
        gsl_eigen_symmv_workspace *memory_allocation = gsl_eigen_symmv_alloc(4*sizeof_row);
        gsl_eigen_symmv(user_2d_array, eigenvalues, eigenvectors, memory_allocation);
        gsl_eigen_symmv_free(memory_allocation);
        gsl_matrix_set_all(user_2d_array, 0.0);
        for(unsigned int i = 0; i <= (sizeof_row - 1); i++)
        {
            for(unsigned int j = 0; j <= (sizeof_column - 1); j++)
            {
                gsl_matrix_set(user_2d_array, 
                               i, 
                               j, 
                               gsl_matrix_get(eigenvectors, i, j)/sqrt(gsl_vector_get(eigenvalues, j)));
            }
        }
        is_const_array = true;
        gsl_matrix_free(eigenvectors);
        gsl_vector_free(eigenvalues);
        gsl_matrix *user_array_transposed = gsl_matrix_calloc(sizeof_row, sizeof_column); 
        gsl_matrix_transpose_memcpy(user_array_transposed, user_2d_array);
        gsl_matrix *temp_given_array = gsl_matrix_calloc(sizeof_row, sizeof_column);
        gsl_matrix_swap(given_array.user_2d_array, temp_given_array);
        gsl_blas_dgemm(CblasNoTrans,
                       CblasNoTrans,
                       1.0,
                       user_array_transposed,
                       temp_given_array,
                       1.0,
                       given_array.user_2d_array);
        gsl_matrix_set_all(temp_given_array, 0.0);
        gsl_matrix_free(user_array_transposed);
        gsl_matrix_swap(given_array.user_2d_array, temp_given_array);
        gsl_blas_dgemm(CblasNoTrans,
                       CblasNoTrans,
                       1.0,
                       temp_given_array,
                       user_2d_array,
                       1.0,
                       given_array.user_2d_array);
        gsl_matrix_free(temp_given_array);
    }
}
