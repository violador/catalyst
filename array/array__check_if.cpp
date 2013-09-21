#include "array.hpp"
//
//
//
bool array::check_if(const unsigned int &option)
{
    switch(option)
    {
    case 1: // IS_POSITIVE
    {
        if(is_1d_array and (not deleted_array))
        {
            return (bool) gsl_vector_ispos(user_1d_array);
        }
        else if(is_2d_array and (not deleted_array))
        {
            return (bool) gsl_matrix_ispos(user_2d_array);
        }
        else if(is_3d_array and (not deleted_array))
        {
        }
        else if(is_4d_array and (not deleted_array))
        {
        }
        else
        {
            return false;
        }
    } 
    break;
    case 2: // IS_NEGATIVE
    {
        if(is_1d_array and (not deleted_array))
        {
            return (bool) gsl_vector_isneg(user_1d_array);
        }
        else if(is_2d_array and (not deleted_array))
        {
            return (bool) gsl_matrix_isneg(user_2d_array);
        }
        else if(is_3d_array and (not deleted_array))
        {
        }
        else if(is_4d_array and (not deleted_array))
        {
        }
        else
        {
            return false;
        }
    } 
    break;
    case 3: // IS_NULL
    {
        if(is_1d_array and (not deleted_array))
        {
            return (bool) gsl_vector_isnull(user_1d_array);
        }
        else if(is_2d_array and (not deleted_array))
        {
            return (bool) gsl_matrix_isnull(user_2d_array);
        }
        else if(is_3d_array and (not deleted_array))
        {
        }
        else if(is_4d_array and (not deleted_array))
        {
        }
        else
        {
            return false;
        }
    } 
    break;
    case 4: // IS_CONSTANT
    {
        return is_const_array;
    } 
    break;
    case 5: // IS_SQUARE
    {
        return is_square_array;
    }
    break;
    case 6: // IS_CREATED
    {
        return created_array;
    }
    break;
    case 7: // IS_DELETED
    {
        return deleted_array;
    }
    break;
    default: return false;
    }
    return false;
}
