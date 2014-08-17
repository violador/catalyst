//
//
//
/// @brief If the current array was previously initialized, either by the
///        constructor or the array::create() member function, array::sort()
///        sorts the current values in some order.
//
/// @return @c EXIT_SUCCESS or @c EXIT_FAILURE.
//
inline int sort()
{
	switch(data != NULL)
	{
		case true:
		{
			std::sort(data, data_end());
			return EXIT_SUCCESS;
		}
		case false:
		{
			return EXIT_FAILURE;
		}
	}
};
