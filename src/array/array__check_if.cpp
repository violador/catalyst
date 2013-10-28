#include "array.hpp"
//
//
//
bool array::check_if(const unsigned int &option)
{
    switch(option)
    {
        case IS_POSITIVE:
        {
            if(is_1d_array and (not deleted_array))
            {
                return (bool) gsl_vector_ispos(&gsl_1d_view.vector);
            }
            else if(is_2d_array and (not deleted_array))
            {
                return (bool) gsl_matrix_ispos(&gsl_2d_view.matrix);
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
        case IS_NEGATIVE:
        {
            if(is_1d_array and (not deleted_array))
            {
                return (bool) gsl_vector_isneg(&gsl_1d_view.vector);
            }
            else if(is_2d_array and (not deleted_array))
            {
                return (bool) gsl_matrix_isneg(&gsl_2d_view.matrix);
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
        case IS_NULL:
        {
            if(is_1d_array and (not deleted_array))
            {
                return (bool) gsl_vector_isnull(&gsl_1d_view.vector);
            }
            else if(is_2d_array and (not deleted_array))
            {
                return (bool) gsl_matrix_isnull(&gsl_2d_view.matrix);
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
        case IS_CONSTANT:
        {
            return is_const_array;
        } 
        break;
        case IS_SQUARE:
        {
            return is_square_array;
        }
        break;
        case IS_CREATED:
        {
            return created_array;
        }
        break;
        case IS_DELETED:
        {
            return deleted_array;
        }
        break;
        case IS_TRANSPOSED:
        {
            return is_transposed;
        }
        break;
    }
    return false;
}
