// ../src/array/array__build_orthonormalizer_form.cpp ======================================= //
//
// Catalyst Lib is free software:  you can redistribute it and/or modifyit under the terms of
// the GNU General Public License as published bythe Free Software Foundation, either version
// 3 of the License, or(at your option) any later version.
//
// Catalyst Lib is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
// without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with Catalyst Lib.
// If not, see <http://www.gnu.org/licenses/>.
//
// ========================================================================================== //
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
/// @cite gsl szabo-1996
//
void array::build_orthonormalizer_form()
{
//
/// @warning @modification_warn
//
	switch(is_2d_array
			and (not deleted_array)
			and (not is_const_array))
 	{
		case true:
//      (1) To allocate memory for the eigenvectors.
//      (2) To allocate memory for the eigenvalues.
//      (3) To allocate memory for an eigen system computation.
//      (4) To compute the eigenvalues and eigenvectors.
//      (5) To deallocate the memory for the eigen system computation.
//      (6) To build the transformation matrix form.
		gsl_matrix *eigenvectors = gsl_matrix_calloc(sizeof_row, sizeof_column);            // (1)
		gsl_vector *eigenvalues = gsl_vector_calloc(sizeof_row);                            // (2)
		gsl_eigen_symmv_workspace *memory_allocation = gsl_eigen_symmv_alloc(4*sizeof_row); // (3)
		gsl_eigen_symmv(&gsl_2d_view.matrix, eigenvalues, eigenvectors, memory_allocation); // (4)
		gsl_eigen_symmv_free(memory_allocation);                                            // (5)
		gsl_matrix_set_zero(&gsl_2d_view.matrix);
		unsigned int i = 0;
		#pragma omp parallel for private(i) ordered schedule(dynamic)
		for(i = 0; i < sizeof_row; ++i)
		{
			unsigned int j = 0;
			#pragma omp parallel for private(j) ordered schedule(dynamic)
			for(j = 0; j < sizeof_column; ++j)
			{
				double a = eigenvectors -> data[i*eigenvectors -> tda + j]
						 / std::sqrt(eigenvalues -> data[j*eigenvalues -> stride]);
				user_2d_array[i*sizeof_row + j] = a;                                        // (6)
			}
		}
		gsl_matrix_free(eigenvectors);
		gsl_vector_free(eigenvalues);
		is_const_array = true;
		break;
	}
}
