//
//
//
/// @brief Returns the elapsed user time.
//
/// @return The time value in a string pattern.
//
inline std::string elapsed_user_time()
{
	return boost::timer::format(chronometer.boost::timer::cpu_timer::elapsed(),
	                            timer_length,
	                            "%u");
};
