#include "array.hpp"
//
//
//
/// @brief Works on not deleted arrays and deallocates the current
///        memory used, resets the internal properties and turns @c
///        true the private @c deleted_array data member.
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
/*
		#pragma omp section
		{
			reset_properties();
			deleted_array = true;
		}
*/
	}
//
/// @note This function do not replace the class destructor which
///       will be invoked by default at the right moment.
//
}
