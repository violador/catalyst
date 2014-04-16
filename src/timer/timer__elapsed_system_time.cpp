//
//
//
/// @brief Returns the elapsed system time.
//
/// @return The time value in a string pattern.
//
inline std::string elapsed_system_time()
{
	return boost::timer::format(chronometer.boost::timer::cpu_timer::elapsed(),
	                            timer_length,
	                            "%s");
};
