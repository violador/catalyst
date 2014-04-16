#include "array.hpp"
//
//
//
/// @brief Checks if the current values of the array are null,
///        only if it is not a deleted object.
//
/// @return @c true if the current array is null, and @c false
///         otherwise.
//
bool array::is_null()
{
//
/// @warning The current functions is not yet implemented
///          for 3D and 4D arrays.
//
	bool buffer = false;
	#pragma omp sections nowait
	{
		#pragma omp section
		{
			switch(is_1d_array and (not deleted_array))
			{
				case true:
				buffer = bool(gsl_vector_isnull(&gsl_1d_view.vector));
				break;
			}
		}
		#pragma omp section
		{
			switch(is_2d_array and (not deleted_array))
			{
				case true:
				buffer = bool(gsl_matrix_isnull(&gsl_2d_view.matrix));
				break;
			}
		}
		#pragma omp section
		{
			switch(is_3d_array and (not deleted_array))
			{
				case true:
				buffer = false;
				break;
			}
		}
		#pragma omp section
		{
			switch(is_4d_array and (not deleted_array))
			{
				case true:
				buffer = false;
				break;
			}
		}
	}
	return buffer;
}
