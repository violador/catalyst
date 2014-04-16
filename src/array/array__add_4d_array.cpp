// ../src/array/array__add_4d_array.cpp ===================================================== //
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
//
//
//
/// @param [in] b A real number.
//
/// @brief A private helper function to add the factor @c b to all
///        the elements of the current 4D array.
//
/// @return None.
//
inline void add_4d_array(const double &b)
{
//
/// @warning Make sure to invoke this function only when the current
///          array is a 4D type.
//
	unsigned int i = 0;
	#pragma omp parallel for private(i) ordered schedule(dynamic)
	for(i = 0; i < sizeof_row; ++i)
	{
		unsigned int j = 0;
		#pragma omp parallel for private(j) ordered schedule(dynamic)
		for(j = 0; j < sizeof_column; ++j)
		{
			unsigned int m = 0;
			#pragma omp parallel for private(m) ordered schedule(dynamic)
			for(m = 0; m < sizeof_1st_layer; ++m)
			{
				unsigned int n = 0;
				#pragma omp parallel for private(n) ordered schedule(dynamic)
				for(n = 0; n < sizeof_2nd_layer; ++n)
				{
					user_4d_array[i][j][m][n] += b;
				}
			}
		}
	}
};
//
//
//
/// @param [in] b A 4D array.
//
/// @brief A private helper function to add the given array, @c b, to
///        the current one if they are both 4D type and its dimension
///        sizes fits.
//
/// @return None.
//
inline void add_4d_array(const array &b)
{
//
/// @warning Make sure to invoke this function only when the current
///          array and @c b are both 4D type.
//
	switch(this -> sizeof_row == b.sizeof_row
			and (this -> sizeof_column == b.sizeof_column)
			and (this -> sizeof_1st_layer == b.sizeof_1st_layer)
			and (this -> sizeof_2nd_layer == b.sizeof_2nd_layer))
	{
		case true:
		unsigned int i = 0;
		#pragma omp parallel for private(i) ordered schedule(dynamic)
		for(i = 0; i < this -> sizeof_row; ++i)
		{
			unsigned int j = 0;
			#pragma omp parallel for private(j) ordered schedule(dynamic)
			for(j = 0; j < this -> sizeof_column; ++j)
			{
				unsigned int m = 0;
				#pragma omp parallel for private(m) ordered schedule(dynamic)
				for(m = 0; m < this -> sizeof_1st_layer; ++m)
				{
					unsigned int n = 0;
					#pragma omp parallel for private(n) ordered schedule(dynamic)
					for(n = 0; n < this -> sizeof_2nd_layer; ++n)
					{
						this -> user_4d_array[i][j][m][n] += b.user_4d_array[i][j][m][n];
					}
				}
			}
		}
		break;
	}
};
//
//
//
/// @param [in] b A real number.
//
//  @param [in] a The array to have its elements added.
//
/// @brief A private helper function to add the factor @c b to all
///        the elements of the given 4D array.
//
/// @return None.
//
inline void add_4d_array(array &a, const double &b)
{
//
/// @warning Make sure to invoke this function only when the given
///          array @c a is a 4D type. Also notice that the content
///          of @c a is going to be modified.
//
	unsigned int i = 0;
	#pragma omp parallel for private(i) ordered schedule(dynamic)
	for(i = 0; i < a.sizeof_row; ++i)
	{
		unsigned int j = 0;
		#pragma omp parallel for private(j) ordered schedule(dynamic)
		for(j = 0; j < a.sizeof_column; ++j)
		{
			unsigned int m = 0;
			#pragma omp parallel for private(m) ordered schedule(dynamic)
			for(m = 0; m < a.sizeof_1st_layer; ++m)
			{
				unsigned int n = 0;
				#pragma omp parallel for private(n) ordered schedule(dynamic)
				for(n = 0; n < a.sizeof_2nd_layer; ++n)
				{
					a.user_4d_array[i][j][m][n] += b;
				}
			}
		}
	}
};