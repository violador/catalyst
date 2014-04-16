//
//
//
//
/// @brief A help function used to deallocate the current
///        memory for a 2D array.
//
/// @return None.
//
inline void delete_2d_array()
{
	delete[] user_2d_array;
	user_2d_array = NULL;
};
