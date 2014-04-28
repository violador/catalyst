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
	for(unsigned int i = 0; i < rank1; ++i)
	{
		for(unsigned int j = 0; j < rank2; ++j)
		{
			for(unsigned int m = 0; m < rank3; ++m)
			{
				delete[] data4[i][j][m];
			}
			delete[] data4[i][j];
		}
		delete[] data4[i];
	}
	delete[] data4;
	data4 = NULL;
};
