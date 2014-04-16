//
//
//
/// @brief A help function used to deallocate the current memory
///        for a 4D array.
//
/// @return None.
//
inline void delete_4d_array()
{
	#pragma omp for schedule(static) nowait
	for(unsigned int i = 0; i < sizeof_row; ++i)
	{
		for(unsigned int j = 0; j < sizeof_column; ++j)
		{
			for(unsigned int m = 0; m < sizeof_column; ++m)
			{
				delete[] user_4d_array[i][j][m];
			}
			delete[] user_4d_array[i][j];
		}
		delete[] user_4d_array[i];
	}
	delete[] user_4d_array;
	user_4d_array = NULL;
};
