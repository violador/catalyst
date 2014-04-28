#include "array.hpp"
//
//
//
/// @param [out] V A not constant array.
//
/// @param [out] S A not constant array.
//
/// @brief If the current array is a 2D, not deleted, not constant and a general
///        rectangular matrix, this function calls the GSL library to compute the
///        singular value decomposition by means of Jacobi orthogonalization method,
///        @f$ A = USV^{T} @$f, if @c rank1 > @c rank2. Where, @f$ S @f$
///        is a @c rank2 vector with the diagonal matrix singular values; @f$
///        V_{T} @f$ is a matrix transposed and the current array will be replaced by
///        the elements of @f$ U @f$. If either @c V or @c S do not have the size
///        needed, they will be properly resized on the fly.
//
/// @return @c EXIT_SUCCESS or @c EXIT_FAILURE.
//
int array::build_jacobi_svd(array &V, array &S)
{
	switch(is_2d()
	       && is_okay()
	       && V.is_okay()
	       && S.is_okay()
	       && rank1 > rank2)
	{
		case true:
		#pragma omp sections nowait
		{
			#pragma omp section
			{
				S.resize(rank2);
			}
			#pragma omp section
			{
				V.resize(rank2, rank2);
			}
		}
		gsl_linalg_SV_decomp_jacobi(&gsl_2d_view.matrix,
	 	                            &V.gsl_2d_view.matrix,
		                            &S.gsl_1d_view.vector);
		V.transpose();
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}
