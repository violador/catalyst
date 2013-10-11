#include "array.hpp"
//
//
//
void array::save_eigens_to(array &eigenvalues, array &eigenvectors)
{
//  (1) To invoke the GSL gsl_eigen_symmv() member function to handle the calculation of
//      eigenvalues and eigenvectors from the current array.
    if(is_2d_array)
    {
        gsl_eigen_symmv_workspace *memory_allocation = gsl_eigen_symmv_alloc(4*sizeof_row);
        gsl_eigen_symmv(user_2d_array, 
                        eigenvalues.user_1d_array, 
                        eigenvectors.user_2d_array, 
                        memory_allocation);                                                 // (1)
        gsl_eigen_symmv_free(memory_allocation);
    }
}
