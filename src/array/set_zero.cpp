//
//
//
/// @brief Sets zero in all the elements, if the array was previously
///        initialized either by the constructor or the array::create()
///        member function. Otherwise nothing is really done.
//
/// @return @c EXIT_SUCCESS or @c EXIT_FAILURE.
//
inline int set_zero()
{
	switch(data != NULL)
	{
		case true:
		{
			#pragma omp critical
			std::fill(data, data_end(), data_type(0.0));
			return EXIT_SUCCESS;
		}
		case false:
		{
			return EXIT_FAILURE;
		}
	}
};
