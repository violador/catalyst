#include "array.hpp"
//
//
//
void array::save_eigens_to(array &eigenvalues, array &eigenvectors)
{
    if(is_2d_array)
    {
        gsl_eigen_symmv_workspace *memory_allocation = gsl_eigen_symmv_alloc(4*sizeof_row);
//
        gsl_eigen_symmv(&gsl_2d_view.matrix, 
                        &eigenvalues.gsl_1d_view.vector, 
                        &eigenvectors.gsl_2d_view.matrix, 
                        memory_allocation);
//
        gsl_eigen_symmv_free(memory_allocation);
    }
}
