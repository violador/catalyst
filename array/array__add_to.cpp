#include "array.hpp"
//
//
//
void array::add_to(array &given_array)
{
//  (1) To add the current vector to the given one.
//  (2) To add the current matrix to the given one.
    if(is_1d_array && given_array.is_1d_array)
    {
        if(sizeof_row == given_array.sizeof_row)
        {
            gsl_vector_add(given_array.user_1d_array, user_1d_array);                              // (1)
        }
    }
    else if(is_2d_array && given_array.is_2d_array)
    {
        if((sizeof_row == given_array.sizeof_row) && (sizeof_column == given_array.sizeof_column))
        {
            gsl_matrix_add(given_array.user_2d_array, user_2d_array);                              // (2)
        }
    }
    else if(is_3d_array)
    {
//      To be implemented someday.
    }
    else if(is_4d_array)
    {
//      To be implemented someday.
    }
}
