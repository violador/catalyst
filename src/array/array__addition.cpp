// ../src/array/array__addition.cpp ========================================================= //
//
// Catalyst Lib is free software:  you can redistribute it and/or modifyit under the terms of
// the GNU General Public License as published bythe Free Software Foundation, either version
// 3 of the License, or(at your option) any later version.
//
// Catalyst Lib is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
// without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with Catalyst Lib.
// If not, see <http://www.gnu.org/licenses/>.
//
// ========================================================================================== //
#include "array.hpp"
//
//
//
/// @author Humberto Jr.
//
/// @date 07/2013
//
/// @param [in] b A real number of @c double type.
//
/// @brief Sums the @c b factor to all elements of the current array
///        and returns the new array using the basic assignment
///        operator, @c =. The operation is valid for all arrays types.
//
/// @return @f$ A + b @f$
//
/// @cite
//
array array::operator +(const double &b)
{
//
/// @note Notice that this operator needs to create a temporary
///       object and also needs to return it by value. Thus, it
///       is a good practice to use the @c += operator instead.
//
	array a = *this;

	#pragma omp parallel sections num_threads(4)
	{
		#pragma omp section
		{
			switch(this -> is_1d_array)
			{
				case true:
				add_1d_array(a, b);
				break;
			}
		}
		#pragma omp section
		{
			switch(this -> is_2d_array)
			{
				case true:
				add_2d_array(a, b);
				break;
			}
		}
		#pragma omp section
		{
			switch(this -> is_3d_array)
			{
				case true:
				add_3d_array(a, b);
				break;
			}
		}
		#pragma omp section
		{
			switch(this -> is_4d_array)
			{
				case true:
				add_4d_array(a, b);
				break;
			}
		}
	}
	return a;
}
//
//
//
/// @author Humberto Jr.
//
/// @date 07/2013
//
/// @param[in] b A real number.
//
/// @brief Sums the array @c b to the current array @c A, and returns
///        the new array using the basic assignment operator, @c =.
///        The operation is valid for all arrays types.
//
/// @return @f$ A + b @f$
//
/// @cite
//
array array::operator +(const array &b)
{
//
/// @note Notice that this operator needs to create a temporary
///       object and also needs to return it by value. Thus, it
///       is a good practice to use the @c += operator instead.
//
	array a = *this;
	#pragma omp parallel sections num_threads(4)
	{
		#pragma omp section
		{
			switch(this -> is_1d_array)
			{
				case true:
				add_1d_array(a, b);
				break;
			}
		}
		#pragma omp section
		{
			switch(this -> is_2d_array)
			{
				case true:
				add_2d_array(a, b);
				break;
			}
		}
		#pragma omp section
		{
			switch(this -> is_3d_array)
			{
				case true:
				//add_3d_array(a, b);
				break;
			}
		}
		#pragma omp section
		{
			switch(this -> is_4d_array)
			{
				case true:
				//add_4d_array(a, b);
				break;
			}
		}
	}
	return a;
}
