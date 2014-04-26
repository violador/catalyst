//
//
//
/// @brief Starts the time elapsed measurement if not started already.
//
/// @return None.
//
inline void start()
{
	switch(stopped)
	{
		case true:
		stopped = false;
		clock.boost::timer::cpu_timer::start();
		return;
	}
};
