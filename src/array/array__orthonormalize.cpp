#include "array.hpp"
//
//
//
void array::orthonormalize(array &given_array)
{
    switch(not given_array.is_const_array)
    {
        case true:
        double *array_buffer = new double[given_array.sizeof_row*given_array.sizeof_column];
        gsl_matrix_view gsl_buffer_view = gsl_matrix_view_array(array_buffer, given_array.sizeof_row, given_array.sizeof_column);
        gsl_matrix_set_zero(&gsl_buffer_view.matrix);
        gsl_matrix_swap(&gsl_buffer_view.matrix, &given_array.gsl_2d_view.matrix);
//
        cblas_dgemm(CblasRowMajor,
                    CblasTrans,
                    CblasNoTrans,
                    sizeof_row,
                    sizeof_column,
                    given_array.sizeof_row,
                    1.0,
                    user_2d_array,
                    sizeof_column,
                    array_buffer,
                    given_array.sizeof_column,
                    1.0,
                    given_array.user_2d_array,
                    given_array.sizeof_column);
//
        gsl_matrix_set_zero(&gsl_buffer_view.matrix);
        gsl_matrix_swap(&gsl_buffer_view.matrix, &given_array.gsl_2d_view.matrix);
//
        cblas_dgemm(CblasRowMajor,
                    CblasNoTrans,
                    CblasNoTrans,
                    given_array.sizeof_row,
                    given_array.sizeof_column,
                    sizeof_row,
                    1.0,
                    array_buffer,
                    given_array.sizeof_column,
                    user_2d_array,
                    sizeof_column,
                    1.0,
                    given_array.user_2d_array,
                    given_array.sizeof_column);
//
        delete[] array_buffer;
        break;
    }
}
