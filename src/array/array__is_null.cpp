#include "array.hpp"
//
//
//
/// @brief Checks if the current values of the array are null,
///        only if it is !a is_deleted object.
//
/// @return @c true if the current array is null, and @c false
///         otherwise.
//
bool array::is_null() const
{
	bool buffer = false;
	#pragma omp sections nowait
	{
		#pragma omp section
		{
			switch(!is_deleted() && is_1d())
			{
				case true:
				buffer = bool(gsl_vector_isnull(&gsl_1d_view.vector));
				break;
			}
		}
		#pragma omp section
		{
			switch(!is_deleted() && is_2d())
			{
				case true:
				buffer = std::all_of(data2, data2 + (rank1*rank2), tools::is_null);
				//buffer = bool(gsl_matrix_isnull(&gsl_2d_view.matrix));
				break;
			}
		}
//
/// @warning The current functions is !yet implemented
///          for 3D and 4D arrays.
//
		#pragma omp section
		{
			switch(is_3d() and (!is_deleted()))
			{
				case true:
				buffer = false;
				break;
			}
		}
		#pragma omp section
		{
			switch(is_4d() and (!is_deleted()))
			{
				case true:
				buffer = false;
				break;
			}
		}
	}
	return buffer;
}
