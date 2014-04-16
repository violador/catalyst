//
//
//
/// @brief Return the current time in the following format: 
///        @c "Sat Oct 12 00:24:17 2013".
//
/// @return A string pattern.
//
inline std::string check_current_time()
{
	time_t current_time = time(0);
	return tools::convert<std::string>(ctime(&current_time));
};
