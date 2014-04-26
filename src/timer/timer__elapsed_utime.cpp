//
//
//
/// @brief Returns the elapsed user time.
//
/// @return The time value in a string pattern.
//
inline std::string elapsed_utime()
{
	return boost::timer::format(clock.boost::timer::cpu_timer::elapsed(),
	                            timer_length,
	                            "%u");
};
