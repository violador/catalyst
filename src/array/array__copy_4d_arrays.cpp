//
//
//
inline void copy_4d_arrays(const array &B)
{
	resize(B.rank1,
	       B.rank2,
	       B.rank3,
	       B.rank4);
	#pragma omp for schedule(static) nowait
	for(unsigned int i = 0; i < rank1; ++i)
	{
		for(unsigned int j = 0; j < rank2; ++j)
		{
			for(unsigned int m = 0; m < rank3; ++m)
			{
				for(unsigned int n = 0; n < rank4; ++n)
				{
					this -> data4[i][j][m][n] = B.data4[i][j][m][n];
				}
			}
		}
	}
};
