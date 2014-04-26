//
//
//
/// @brief Returns the elapsed system time.
//
/// @return The time value in a string pattern.
//
inline std::string elapsed_stime()
{
	return boost::timer::format(clock.boost::timer::cpu_timer::elapsed(),
	                            timer_length,
	                            "%s");
};
