//
//
//
/// @brief Returns the last elapsed wall time, i.e. after
///        invoke the timer::stop() member function. If
///        the current timer is running it will return
///        the last wall time anyway.
//
/// @return The time value in a string pattern.
//
inline std::string wall_time()
{
	return wtime[counter];
};
