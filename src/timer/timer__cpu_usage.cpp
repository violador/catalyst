//
//
//
/// @brief Returns the last elapsed cpu usage, i.e. after
///        invoke the timer::stop() member function. If
///        the current timer is running it will return
///        the last cpu usage anyway.
//
/// @return The time value in a string pattern.
//
inline std::string cpu_usage()
{
	return usage[counter];
};
