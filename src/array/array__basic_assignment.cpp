#include "array.hpp"
//
//
//
/// @param [in] input A previously declared array object.
//
/// @brief The definition for the operator @c = used to copy
///        the elements from the given @c input array to the
///        current one. If either the type or size of @c input
///        is different, the current object will be resized
///        properly.
//
/// @return None.
//
void array::operator =(const array &input)
{
	#pragma omp sections nowait
	{
		#pragma omp section
		{
			switch(input.is_1d() && this -> is_okay())
			{
				case true:
				resize(input.sizeof_row);
				copy_1d_arrays(input);
				break;
			}
		}
		#pragma omp section
		{
			switch(input.is_2d() && this -> is_okay())
			{
				case true:
				resize(input.sizeof_row,
				       input.sizeof_column);
				copy_2d_arrays(input);
				break;
			}
		}
		#pragma omp section
		{
			switch(input.is_3d() && this -> is_okay())
			{
				case true:
				resize(input.sizeof_row,
				       input.sizeof_column,
				       input.sizeof_1st_layer);
				copy_3d_arrays(input);
				break;
			}
		}
		#pragma omp section
		{
			switch(input.is_4d() && this -> is_okay())
			{
				case true:
				resize(input.sizeof_row,
				       input.sizeof_column,
				       input.sizeof_1st_layer,
				       input.sizeof_2nd_layer);
				copy_4d_arrays(input);
				break;
			}
		}
	}
//
/// @note Notice that the type and dimensions of the current
///       object is going to be changed if they do not fit
///       those from the given @c input. To overcome this
///       eventual extra task, it is interesting to use the
///       operator between objects with the same dimensions.
//
}
