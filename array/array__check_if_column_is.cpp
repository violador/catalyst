#include "array.hpp"
//
//
//
bool array::check_if_column_is(const unsigned int &option, const unsigned int &j)
{
    if(is_2d_array)
    {
        if((j > 0) && (j <= sizeof_column))
        {
            switch(option)
            {
            case 1:
            { 
                gsl_vector_const_view array_column = gsl_matrix_const_row(user_2d_array, j - 1);
                return (bool) gsl_vector_ispos(&array_column.vector);
            } 
            break;
            case 2:
            {
                gsl_vector_const_view array_column = gsl_matrix_const_row(user_2d_array, j - 1);
                return (bool) gsl_vector_isneg(&array_column.vector);
            }
            break;
            default: return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
