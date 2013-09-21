#include "array.hpp"
//
//
//
void array::copy_to(array &given_array)
{
    if(is_1d_array && given_array.is_1d_array)
    {
        if(sizeof_row == given_array.sizeof_row)
        {
            gsl_vector_memcpy(given_array.user_1d_array, user_1d_array);
        }
    }
    else if(is_2d_array && given_array.is_2d_array)
    {
        if((sizeof_row == given_array.sizeof_row) && (sizeof_column == given_array.sizeof_column))
        {
            gsl_matrix_memcpy(given_array.user_2d_array, user_2d_array);
        }
    }
    else if(is_3d_array && given_array.is_3d_array)
    {
//      To be implemented someday!
    }
    else if(is_4d_array && given_array.is_4d_array)
    {
//      To be implemented someday!
    }
}
