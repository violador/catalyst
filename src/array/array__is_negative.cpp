#include "array.hpp"
//
//
//
/// @brief Checks if the current values of the array are negative,
///        only if it is not a deleted object.
//
/// @return @c true if the current array is negative, and @c false
///         otherwise.
//
bool array::is_negative() const
{
	bool buffer = false;
	#pragma omp sections nowait
	{
		#pragma omp section
		{
			switch(is_1d() && (!is_deleted()))
			{
				case true:
				buffer = bool(gsl_vector_isneg(&gsl_1d_view.vector));
				break;
			}
		}
		#pragma omp section
		{
			switch(is_2d() && (!is_deleted()))
			{
				case true:
				buffer = bool(gsl_matrix_isneg(&gsl_2d_view.matrix));
				break;
			}
		}
//
/// @warning This function is not yet implemented for 3D and 4D
///          arrays.
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
