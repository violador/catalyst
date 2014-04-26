#include "array.hpp"
//
//
//
void array::operator +=(const array &B)
{
	#pragma omp sections nowait
	{
		#pragma omp section
		{
			switch(this -> is_1d()
			       && this -> is_okay()
			       && B.is_1d())
			{
				case true:
				add_1d_arrays(*this, B);
				break;
			}
		}
		#pragma omp section
		{
			switch(this -> is_2d()
			       && this -> is_okay()
			       && B.is_2d())
			{
				case true:
				add_1d_arrays(*this, B);
				break;
			}
		}
		#pragma omp section
		{
			switch(this -> is_3d()
			       && this -> is_okay()
			       && B.is_3d())
			{
				case true:
				add_3d_arrays(*this, B);
				break;
			}
		}
		#pragma omp section
		{
			switch(this -> is_4d()
			       && this -> is_okay()
			       && B.is_4d())
			{
				case true:
				add_4d_arrays(*this, B);
				break;
			}
		}
	}
}
