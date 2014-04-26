//
//
//
/// @brief Returns the last elapsed user time, i.e. after
///        invoke the timer::stop() member function. If
///        the current timer is running it will return
///        the last user time anyway.
//
/// @return The time value in a string pattern.
//
inline std::string user_time()
{
	return utime[counter];
};
