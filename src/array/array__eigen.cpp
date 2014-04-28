#include "array.hpp"
//
//
//
/// @param [out] values An 1D, not constant and not deleted array
///                     to store the eigenvalues.
//
/// @param [out] vectors A 2D, not constant and not deleted array
///                      to store the eigenvectors.
//
/// @brief Calls the GSL library to calculate the eigenvalues and
///        eigenvectors of the current array if it is a 2D and not
///        deleted one. The results are stored in the given @c
///        values and @c vectors arrays.
//
/// @return @c EXIT_SUCCESS or @c EXIT_FAILURE.
//
int array::eigen(array &values, array &vectors)
{
	switch(this -> is_2d()
	       && this -> not_deleted()
	       && values.is_okay()
	       && vectors.is_okay())
	{
		case true:
		values.resize(this -> rank1);
		vectors.resize(this -> rank1, this -> rank2);
		work_space = gsl_eigen_symmv_alloc(this -> rank1*4);
		gsl_eigen_symmv(&this -> gsl_2d_view.matrix,
		                &values.gsl_1d_view.vector,
		                &vectors.gsl_2d_view.matrix,
		                work_space);
		gsl_eigen_symmv_free(work_space);
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}
