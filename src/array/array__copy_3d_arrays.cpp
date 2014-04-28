//
//
//
inline void copy_3d_arrays(const array &B)
{
	resize(B.rank1,
	       B.rank2,
	       B.rank3);
	#pragma omp for schedule(static) nowait
	for(unsigned int i = 0; i < rank1; ++i)
	{
		for(unsigned int j = 0; j < rank2; ++j)
		{
			for(unsigned int m = 0; m < rank3; ++m)
			{
				this -> data3[i][j][m] = B.data3[i][j][m];
			}
		}
	}
};
