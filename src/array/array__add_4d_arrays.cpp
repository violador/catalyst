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
	for(unsigned int i = 0; i < A.rank1; ++i)
	{
		for(unsigned int j = 0; j < A.rank2; ++j)
		{
			for(unsigned int m = 0; m < A.rank3; ++m)
			{
				for(unsigned int n = 0; n < A.rank4; ++n)
				{
					A.data4[i][j][m][n] += b;
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
	switch(A.rank1 == B.rank1
	       && A.rank2 == B.rank2
	       && A.rank3 == B.rank3
	       && A.rank4 == B.rank4)
	{
		case true:
		#pragma omp for schedule(static)
		for(unsigned int i = 0; i < A.rank1; ++i)
		{
			for(unsigned int j = 0; j < A.rank2; ++j)
			{
				for(unsigned int m = 0; m < A.rank3; ++m)
				{
					for(unsigned int n = 0; n < A.rank4; ++n)
					{
						A.data4[i][j][m][n] += B.data4[i][j][m][n];
					}
				}
			}
		}
		return;
	}
};
