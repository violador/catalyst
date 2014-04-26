//
//
//
/// @brief Returns the elapsed wall time.
//
/// @return The time value in a string pattern.
//
inline std::string elapsed_wtime()
{
	return boost::timer::format(clock.boost::timer::cpu_timer::elapsed(),
	                            timer_length,
	                            "%w");
};
