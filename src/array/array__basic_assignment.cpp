#include "array.hpp"
//
//
//
void array::operator =(const array &B)
{
	#pragma omp sections
	{
		#pragma omp section
		{
			switch(this -> is_1d_array
			       && B.is_1d_array
			       && (!this -> is_const_array)
			       && (!this -> deleted_array))
			{
				case true:
				copy_1d_arrays(B);
				break;
			}
		}
		#pragma omp section
		{
			switch(this -> is_2d_array
			       && B.is_2d_array
			       && (!this -> is_const_array)
			       && (!this -> deleted_array))
			{
				case true:
				copy_2d_arrays(B);
				break;
			}
		}
		#pragma omp section
		{
			switch(this -> is_3d_array
			       && B.is_3d_array
			       && (!this -> is_const_array)
			       && (!this -> deleted_array))
			{
				case true:
				copy_3d_arrays(B);
				break;
			}
		}
		#pragma omp section
		{
			switch(this -> is_4d_array
			       && B.is_4d_array
			       && (!this -> is_const_array)
			       && (!this -> deleted_array))
			{
				case true:
				copy_4d_arrays(B);
				break;
			}
		}
	}
}
