#include "array.hpp"
//
//
//
/// @brief Deallocates the current memory used to store the array. This
///        function do not replace the class destructor which will be
///        invoked by default at the right moment but prevents the user
///        to access the object internal content since some of them may
///        be unavailable. If the object is needed after while the user
///        should invoke the array::create() member first.
//
/// @return None.
//
void array::delete_array()
{
	#pragma omp sections nowait
	{
		#pragma omp section
		{
			switch(is_1d())
			{
				case true:
				delete_1d_array();
				break;
			}
		}
		#pragma omp section
		{
			switch(is_2d())
			{
				case true:
				delete_2d_array();
				gsl_eigen_symmv_free(work_space);
				break;
			}
		}
		#pragma omp section
		{
			switch(is_3d())
			{
				case true:
				delete_3d_array();
				break;
			}
		}
		#pragma omp section
		{
			switch(is_4d())
			{
				case true:
				delete_4d_array();
				break;
			}
		}
	}
}
