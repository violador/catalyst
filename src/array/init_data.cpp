//
//
//
/// @param [in] size The first rank length.
//
/// @brief A help function to allocate memory for a rank one array.
//
/// @return @c EXIT_SUCCESS if the allocation was successful, and
///         @c EXIT_FAILURE otherwise.
//
inline int init_data(const unsigned int &size)
{
	data = new (std::nothrow) data_type[size]();
	switch(data != NULL)
	{
		case true:
		{
			rank1 = size;
			return EXIT_SUCCESS;
		}
		case false:
		{
			return EXIT_FAILURE;
		}
	}
};
