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
	delete[] user_1d_array;
	user_1d_array = NULL;
};
