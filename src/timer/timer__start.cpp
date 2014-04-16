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
		++counter;
		chronometer.boost::timer::cpu_timer::start();
		break;
	}
};
