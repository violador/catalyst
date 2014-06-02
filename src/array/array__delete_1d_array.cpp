//
//
//
/// @brief A help function used to deallocate the current
///        memory for a 1D array and to set @c rank1 @c =
///        0.
//
/// @return @c EXIT_SUCCESS.
//
inline int delete_1d_array()
{
	delete[] data;
	data = NULL;
	rank1 = 0;
	return EXIT_SUCCESS;
};
