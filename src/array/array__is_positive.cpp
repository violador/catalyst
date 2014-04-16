#include "array.hpp"
//
//
//
/// @brief Checks if the current values of the array are positive,
///        only if it is !a deleted object.
//
/// @return @c true if the current array is positive, and @c false
///         otherwise.
//
bool array::is_positive() const
{
	bool buffer = false;
	#pragma omp sections nowait
	{
		#pragma omp section
		{
			switch(is_1d() && (!is_deleted()))
			{
				case true:
				buffer = bool(gsl_vector_ispos(&gsl_1d_view.vector));
				break;
			}
		}
		#pragma omp section
		{
			switch(is_2d() && (!is_deleted()))
			{
				case true:
				buffer = bool(gsl_matrix_ispos(&gsl_2d_view.matrix));
				break;
			}
		}
//
/// @warning The current functions is !yet implemented for 3D and
///          4D arrays.
//
		#pragma omp section
		{
			switch(is_3d() && (!is_deleted()))
			{
				case true:
				buffer = false;
				break;
			}
		}
		#pragma omp section
		{
			switch(is_4d() && (!is_deleted()))
			{
				case true:
				buffer = false;
				break;
			}
		}
	}
	return buffer;
}
