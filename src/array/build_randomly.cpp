//
//
//
/// @brief If the current array was previously initialized, either
///        by the constructor or the array::create() member function,
///        array::build_randomly() replaces the data by random numbers
///        generated in the range between zero and five times the rank
///        size.
//
/// @return @c EXIT_SUCCESS or @c EXIT_FAILURE.
//
inline int build_randomly()
{
	switch(data != NULL)
	{
		case  true: return random_1d_array();
		case false: return EXIT_FAILURE;
	}
};
