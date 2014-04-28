//
//
//
/// @brief A help function used to deallocate the current
///        memory for a 3D array.
//
/// @return None.
//
inline void delete_3d_array()
{
	#pragma omp for schedule(static) nowait
	for(unsigned int i = 0; i < rank1; ++i)
	{
		for(unsigned int j = 0; j < rank2; ++j)
		{
			delete[] data3[i][j];
		}
		delete[] data3[i];
	}
	delete[] data3;
	data3 = NULL;
};
