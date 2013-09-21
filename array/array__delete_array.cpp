#include "array.hpp"
//
//
//
void array::delete_array()
{
    if(is_1d_array)
    {
        gsl_vector_free(user_1d_array);
        deleted_array = true;
    }
    else if(is_2d_array)
    {
        gsl_matrix_free(user_2d_array);
        deleted_array = true;
    }
    else if(is_3d_array)
    {
//      To be implemented someday!
        deleted_array = true;
    }
    else if(is_4d_array)
    {
//      To be implemented someday!
        deleted_array = true;
    }
}
