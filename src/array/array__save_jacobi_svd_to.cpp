#include "array.hpp"
//
//
//
void array::save_jacobi_svd_to(array &u_matrix, array &eigenvalues)
{
//  (1) To calculate the SVD using Jacobi's method.
    if(is_2d_array and (not deleted_array))
    {
        gsl_linalg_SV_decomp_jacobi(&gsl_2d_view.matrix, &u_matrix.gsl_2d_view.matrix, &eigenvalues.gsl_1d_view.vector); // (1)
    }
}
