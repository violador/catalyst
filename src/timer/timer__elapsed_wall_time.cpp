//
//
//
/// @brief Returns the elapsed wall time.
//
/// @return The time value in a string pattern.
//
inline std::string elapsed_wall_time()
{
	return boost::timer::format(chronometer.boost::timer::cpu_timer::elapsed(),
	                            timer_length,
	                            "%w");
};
