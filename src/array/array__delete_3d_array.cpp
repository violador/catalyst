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
	for(unsigned int i = 0; i < sizeof_row; ++i)
	{
		for(unsigned int j = 0; j < sizeof_column; ++j)
		{
			delete[] user_3d_array[i][j];
		}
		delete[] user_3d_array[i];
	}
	delete[] user_3d_array;
	user_3d_array = NULL;
};
