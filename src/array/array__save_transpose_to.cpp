#include "array.hpp"
//
//
//
void array::save_transpose_to(array &given_array)
{
    if(this -> is_2d_array 
       and given_array.is_2d_array 
       and (not given_array.is_const_array)
       and this -> sizeof_row == given_array.sizeof_row
       and this -> sizeof_column == given_array.sizeof_column)
    {
        gsl_matrix_transpose_memcpy(&given_array.gsl_2d_view.matrix, &this -> gsl_2d_view.matrix);
    }
}
