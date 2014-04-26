#include "array.hpp"
//
//
//
/// @param [in] b A real number.
//
/// @brief Sums the @c b factor to all elements of the current array
///        and returns the new object using the basic assignment
///        operator, @c =.
//
/// @return @f$ := A + b @f$
//
array array::operator +(const double &b)
{
	array A = *this;
	#pragma omp sections nowait
	{
		#pragma omp section
		{
			switch(is_1d())
			{
				case true:
				add_1d_arrays(A, b);
				break;
			}
		}
		#pragma omp section
		{
			switch(is_2d())
			{
				case true:
				add_2d_arrays(A, b);
				break;
			}
		}
		#pragma omp section
		{
			switch(is_3d())
			{
				case true:
				add_3d_arrays(A, b);
				break;
			}
		}
		#pragma omp section
		{
			switch(is_4d())
			{
				case true:
				add_4d_arrays(A, b);
				break;
			}
		}
	}
//
/// @note Notice that this operator needs to create a temporary
///       object and also needs to return it by value. Thus, it
///       is a good practice to use the @c += operator instead.
//
	return A;
}
//
//
//
/// @param [in] B An @c array type object.
//
/// @brief Sums the array @c B to the current array @c A, and returns
///        the new array using the basic assignment operator, @c =.
///        The operation is valid for all arrays types.
//
/// @return @f$ := A + B @f$
//
array array::operator +(const array &B)
{
	array A = *this;
	#pragma omp sections nowait
	{
		#pragma omp section
		{
			switch(A.is_1d() && B.is_1d())
			{
				case true:
				add_1d_arrays(A, B);
				break;
			}
		}
		#pragma omp section
		{
			switch(A.is_2d() && B.is_2d())
			{
				case true:
				add_2d_arrays(A, B);
				break;
			}
		}
		#pragma omp section
		{
			switch(A.is_3d() && B.is_3d())
			{
				case true:
				add_3d_arrays(A, B);
				break;
			}
		}
		#pragma omp section
		{
			switch(A.is_4d() && B.is_4d())
			{
				case true:
				add_4d_arrays(A, B);
				break;
			}
		}
	}
//
/// @note Notice that this operator needs to create a temporary
///       object and also needs to return it by value. Thus, it
///       is a good practice to use the @c += operator instead.
//
	return A;
}
