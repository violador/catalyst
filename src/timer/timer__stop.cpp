//
//
//
/// @brief Stops the time elapsed measurement if it was started.
//
/// @return None.
//
inline void stop()
{
	switch(stopped)
	{
		case false:
		clock.boost::timer::cpu_timer::stop();
		save_timing();
		return;
	}
};
