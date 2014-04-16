//
//
//
inline void copy_3d_arrays(const array &B)
{
	resize_array(B.sizeof_row,
	             B.sizeof_column,
	             B.sizeof_1st_layer);
	#pragma omp for schedule(static) nowait
	for(unsigned int i = 0; i < sizeof_row; ++i)
	{
		for(unsigned int j = 0; j < sizeof_column; ++j)
		{
			for(unsigned int m = 0; m < sizeof_1st_layer; ++m)
			{
				this -> user_3d_array[i][j][m] = B.user_3d_array[i][j][m];
			}
		}
	}
};
