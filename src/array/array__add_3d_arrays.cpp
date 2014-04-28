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
inline void add_3d_arrays(array &A, const double &b)
{
	#pragma omp for schedule(static) nowait
	for(unsigned int i = 0; i < A.rank1; ++i)
	{
		for(unsigned int j = 0; j < A.rank2; ++j)
		{
			for(unsigned int m = 0; m < A.rank3; ++m)
			{
				A.data3[i][j][m] += b;
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
///        to the given array @c A, if they are both 3D type and
///        its dimension sizes fits.
//
/// @return None.
//
inline void add_3d_arrays(array &A, const array &B)
{
	switch(A.rank1 == B.rank1
	       && A.rank2 == B.rank2
	       && A.rank3 == B.rank3)
	{
		case true:
		#pragma omp for schedule(static) nowait
		for(unsigned int i = 0; i < A.rank1; ++i)
		{
			for(unsigned int j = 0; j < A.rank2; ++j)
			{
				for(unsigned int m = 0; m < A.rank3; ++m)
				{
					A.data3[i][j][m] += B.data3[i][j][m];
				}
			}
		}
		return;
	}
};
