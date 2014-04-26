//
//
//
/// @param [in] b A real number.
//
//  @param [in] A A 4D and non-constant array.
//
/// @brief A private helper function to add the factor @c b to all
///        the elements of the given 4D array.
//
/// @return None.
//
inline void add_4d_arrays(array &A, const double &b)
{
	#pragma omp for schedule(static)
	for(unsigned int i = 0; i < A.sizeof_row; ++i)
	{
		for(unsigned int j = 0; j < A.sizeof_column; ++j)
		{
			for(unsigned int m = 0; m < A.sizeof_1st_layer; ++m)
			{
				for(unsigned int n = 0; n < A.sizeof_2nd_layer; ++n)
				{
					A.user_4d_array[i][j][m][n] += b;
				}
			}
		}
	}
};
//
//
//
/// @param [in] B A 4D array.
//
//  @param [out] A A 4D and non-constant array.
//
/// @brief A private helper function to add the given array @c B
///        to the given array @c A, if they are both 4D type and
///        its dimension sizes fits.
//
/// @return None.
//
inline void add_4d_arrays(array &A, const array &B)
{
	switch(A.sizeof_row == B.sizeof_row
	       && A.sizeof_column == B.sizeof_column
	       && A.sizeof_1st_layer == B.sizeof_1st_layer
	       && A.sizeof_2nd_layer == B.sizeof_2nd_layer)
	{
		case true:
		#pragma omp for schedule(static)
		for(unsigned int i = 0; i < A.sizeof_row; ++i)
		{
			for(unsigned int j = 0; j < A.sizeof_column; ++j)
			{
				for(unsigned int m = 0; m < A.sizeof_1st_layer; ++m)
				{
					for(unsigned int n = 0; n < A.sizeof_2nd_layer; ++n)
					{
						A.user_4d_array[i][j][m][n] += B.user_4d_array[i][j][m][n];
					}
				}
			}
		}
		break;
	}
};
