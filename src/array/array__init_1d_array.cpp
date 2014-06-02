//
//
//
/// @param [in] row The first rank length.
//
/// @brief A help function to allocate memory for an 1D array.
//
/// @return @c EXIT_SUCCESS if the allocation was successful,
///         and @c EXIT_FAILURE otherwise.
//
inline int init_1d_array(const unsigned int &size)
{
	data = new (std::nothrow) data_type[size]();
	switch(data != NULL)
	{
		case false:
		{
			return EXIT_FAILURE;
		}
		case true:
		{
			rank1 = size;
			return EXIT_SUCCESS;
		}
	}
};
