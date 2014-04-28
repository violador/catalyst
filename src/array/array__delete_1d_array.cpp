//
//
//
/// @brief A help function used to deallocate the current
///        memory for a 1D array.
//
/// @return None.
//
inline void delete_1d_array()
{
	delete[] data1;
	data1 = NULL;
};
