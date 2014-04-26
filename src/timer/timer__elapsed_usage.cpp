//
//
//
/// @brief Returns the elapsed CPU usage.
//
/// @return The percentage value in a string pattern.
//
inline std::string elapsed_usage()
{
	return boost::timer::format(clock.boost::timer::cpu_timer::elapsed(),
	                            timer_length,
	                            "%p");
};
