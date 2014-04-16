#include "timer.hpp"
//
//
//
/// @brief Stops the time elapsed measurement if it was started.
//
/// @return None.
//
void timer::stop()
{
	switch(stopped)
	{
		case false:
		chronometer.boost::timer::cpu_timer::stop();
		#pragma omp sections
		{
			#pragma omp section
			{
				wall_time.insert(std::pair<unsigned int, std::string>(counter,
				                                                      elapsed_wall_time()));
			}
			#pragma omp section
			{
				system_time.insert(std::pair<unsigned int, std::string>(counter,
				                                                        elapsed_system_time()));
			}
			#pragma omp section
			{
				user_time.insert(std::pair<unsigned int, std::string>(counter,
				                                                      elapsed_user_time()));
			}
			#pragma omp section
			{
				cpu_usage.insert(std::pair<unsigned int, std::string>(counter,
				                                                      elapsed_cpu_usage()));
			}
			#pragma omp section
			{
				stopped = true;
			}
		}
		break;
	}
};
