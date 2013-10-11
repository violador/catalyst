#include "array.hpp"
//
//
//
void array::save_jacobi_svd_to(array &u_matrix, array &eigenvalues)
{
//  (1) To calculate the SVD using Jacobi's method.
    if(is_2d_array and (not deleted_array))
    {
        gsl_linalg_SV_decomp_jacobi(user_2d_array, u_matrix.user_2d_array, eigenvalues.user_1d_array); // (1)
    }
}
