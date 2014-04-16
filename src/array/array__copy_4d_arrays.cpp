//
//
//
inline void copy_4d_arrays(const array &B)
{
	resize_array(B.sizeof_row,
	             B.sizeof_column,
	             B.sizeof_1st_layer,
	             B.sizeof_2nd_layer);
	#pragma omp for schedule(static) nowait
	for(unsigned int i = 0; i < sizeof_row; ++i)
	{
		for(unsigned int j = 0; j < sizeof_column; ++j)
		{
			for(unsigned int m = 0; m < sizeof_1st_layer; ++m)
			{
				for(unsigned int n = 0; n < sizeof_2nd_layer; ++n)
				{
					this -> user_4d_array[i][j][m][n] = B.user_4d_array[i][j][m][n];
				}
			}
		}
	}
};
