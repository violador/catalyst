//
//
//
/// @param [in] b A real number.
//
//  @param [out] A A 3D and non-constant array.
//
/// @brief A private helper function to add the factor @c b to all
///        the elements of the given array @c A.
//
/// @return None.
//
inline void add_3d_array(array &A, const double &b)
{
	#pragma omp for schedule(static) nowait
	for(unsigned int i = 0; i < A.sizeof_row; ++i)
	{
		for(unsigned int j = 0; j < A.sizeof_column; ++j)
		{
			for(unsigned int m = 0; m < A.sizeof_1st_layer; ++m)
			{
				A.user_3d_array[i][j][m] += b;
			}
		}
	}
};
//
//
//
/// @param [in] B A 3D array.
//
//  @param [out] A A 3D and non-constant array.
//
/// @brief A private helper function to add the given array @c B
///        to the given array @c A.
//
/// @return None.
//
inline void add_3d_array(array &A, const array &B)
{
	#pragma omp for schedule(static) nowait
	for(unsigned int i = 0; i < A.sizeof_row; ++i)
	{
		for(unsigned int j = 0; j < A.sizeof_column; ++j)
		{
			for(unsigned int m = 0; m < A.sizeof_1st_layer; ++m)
			{
				A.user_3d_array[i][j][m] += B.user_3d_array[i][j][m];
			}
		}
	}
};
