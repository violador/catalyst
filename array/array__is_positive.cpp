#include "array.hpp"
//
//
//
bool array::is_positive()
{
    if(is_1d_array)
    {
        return gsl_vector_ispos(user_1d_array);
    }
    else if(is_2d_array)
    {
        return gsl_matrix_ispos(user_2d_array);
    }
}
