//
//
//
/// @brief Generate elements randomly if the current array was previously
///        initialized either by the constructor or the array::create()
///        member function. Otherwise nothing is done. Notice that all the
///        generated numbers might be positive only (including zero). The
///        interval of possible numbers is [0, @c 'first_rank()*5'].
//
/// @return None.
//
void build_randomly()
{
	std::default_random_engine generator(first_rank()/time(NULL));
	std::uniform_real_distribution<data_type> number(0.0, first_rank()*5.0);
	auto set_randomly = [&](data_type &iter)
	{
		iter = number(generator);
	};
	std::for_each(data, data_end(), set_randomly);
};
