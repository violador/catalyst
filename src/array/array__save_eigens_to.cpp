#include "array.hpp"
//
//
//
void array::save_eigens_to(array &values, array &vectors)
{
    switch(is_2d_array and (not deleted_array))
    {
        case true:
        switch(values.is_const_array or vectors.is_const_array)
        {
            case false: break;
            case  true: return; break;
        }
        #pragma omp parallel sections num_threads(2)
        {
            #pragma omp section
            {
                switch(this -> sizeof_row == values.sizeof_row)
                {
                    case false:
                    values.resize_array(this -> sizeof_row); 
                    break;
                }
            }
            #pragma omp section
            {
                switch((this -> sizeof_row == vectors.sizeof_row)
                       and (this -> sizeof_column == vectors.sizeof_column))
                {
                    case false:
                    vectors.resize_array(this -> sizeof_row, this -> sizeof_column); 
                    break;
                }
            }
        }
        gsl_eigen_symmv_workspace *memory_allocation = gsl_eigen_symmv_alloc(this -> sizeof_row*4);
//
        gsl_eigen_symmv(&gsl_2d_view.matrix, 
                        &values.gsl_1d_view.vector, 
                        &vectors.gsl_2d_view.matrix, 
                        memory_allocation);
//
        gsl_eigen_symmv_free(memory_allocation);
        break;
    }
}
