#include "array.hpp"
//
//
//
void array::save_transpose_to(array &given_array)
{
//  (1) To invoke the GSL gsl_matrix_transpose_memcpy() member to handle 
//      the transposition of the current array and to store in the given one.
    if(this -> is_2d_array 
       and given_array.is_2d_array 
       and (not given_array.is_const_array)
       and this -> sizeof_row == given_array.sizeof_row
       and this -> sizeof_column == given_array.sizeof_column)
    {
        gsl_matrix_transpose_memcpy(given_array.user_2d_array, user_2d_array); // (1)
    }
}
