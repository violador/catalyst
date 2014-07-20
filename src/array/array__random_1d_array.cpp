//
//
//
/// @brief A private member function to generate elements randomly,
///        using @c time(NULL)/rank1 as seed.
//
/// @return @c EXIT_SUCCESS.
//
inline int random_1d_array()
{
	std::default_random_engine generator(time(NULL)/rank1);
	std::uniform_real_distribution<data_type> number(0.0, 5.0*rank1);
	auto set_randomly = [&](data_type &iter)
	{
		iter = number(generator);
	};
	std::for_each(data, data_end(), set_randomly);
	return EXIT_SUCCESS;
};
