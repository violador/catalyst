#include "array.hpp"
//
//
//
/// @brief Works on 2D, not deleted and non-constant arrays invoking the GSL library to
///        calculate the canonical orthogonalization matrix from its current elements.
///        Then replaces the current content with the elements of the new calculated
///        matrix. The canonical orthogonalization matrix, @f$ X @f$, is defined as @f[
///        X_{i, j} = \frac{U_{i, j}}{\sqrt{s_{j}}} @f] where @f$ U @f$ are the
///        eigenvectors and @f$ s @f$ the eigenvalues calculated from the current array.
//
/// @return None.
//
void array::build_orthonormalizer_form()
{
//
/// @warning @modification_warn
//
	switch(is_2d() && is_okay())
 	{
		case true:
//      (1) Allocates memory for the eigenvectors, U.
//      (2) Allocates memory for the eigenvalues, s.
//      (3) Allocates memory for an eigen system computation.
//      (4) Computes the s and U.
//      (5) Deallocates the memory for the eigen system computation.
//      (6) Build the transformation matrix form, X.
		gsl_matrix *U = gsl_matrix_calloc(sizeof_row, sizeof_column);                // (1)
		gsl_vector *s = gsl_vector_calloc(sizeof_row);                               // (2)
		gsl_eigen_symmv_workspace *work_space = gsl_eigen_symmv_alloc(4*sizeof_row); // (3)
		gsl_eigen_symmv(&gsl_2d_view.matrix, s, U, work_space);                      // (4)
		gsl_eigen_symmv_free(work_space);                                            // (5)
		gsl_matrix_set_zero(&gsl_2d_view.matrix);
		#pragma omp for schedule(static) nowait
		for(unsigned int i = 0; i < sizeof_row; ++i)
		{
			for(unsigned int j = 0; j < sizeof_column; ++j)
			{
				user_2d_array[i*sizeof_row + j] = U -> data[i*U -> tda + j]
				/std::sqrt(s -> data[j*s -> stride]);                                // (6)
			}
		}
		gsl_matrix_free(U);
		gsl_vector_free(s);
		is_const_array = true;
		return;
	}
}
