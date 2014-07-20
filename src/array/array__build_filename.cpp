//
//
//
/// @brief A private help function that builds a filename with the
///        pattern @c 'array[number]' for the current object. Where,
///        the number is a random number generated between 0 and 10000.
//
/// @return A string pattern.
//
inline std::string build_filename()
{
	std::default_random_engine generator(time(NULL));
	std::uniform_real_distribution<double> id(0, 10000);
	return "array" + tools::convert<std::string>(id(generator));
};
