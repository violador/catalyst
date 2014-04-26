//
//
//
/// @brief Returns the last elapsed system time, i.e. after
///        invoke the timer::stop() member function. If the
///        current timer is running it will return the last
///        system time anyway.
//
/// @return The time value in a string pattern.
//
inline std::string system_time()
{
	return stime[counter];
};
