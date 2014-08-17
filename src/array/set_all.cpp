//
//
//
/// @param [in] input A new value for all the elements.
//
/// @brief Sets the given @c input in all the elements, if the array
///        was previously initialized either by the constructor or
///        the array::create() member function. Otherwise nothing is
///        really done.
//
/// @return @c EXIT_SUCCESS or @c EXIT_FAILURE.
//
inline int set_all(const data_type &input)
{
	switch(data != NULL)
	{
		case true:
		{
			#pragma omp critical
			std::fill(data, data_end(), input);
			return EXIT_SUCCESS;
		}
		case false:
		{
			return EXIT_FAILURE;
		}
	}
};
