#include "timer.hpp"
//
//
//
/// @brief Stops the time elapsed measurement if it was started.
//
/// @return None.
//
void timer::save_timing()
{
	++counter;
	#pragma omp sections nowait
	{
		#pragma omp section
		{
			wtime.insert(std::pair<unsigned int, std::string>(counter, elapsed_wtime()));
		}
		#pragma omp section
		{
			stime.insert(std::pair<unsigned int, std::string>(counter, elapsed_stime()));
		}
		#pragma omp section
		{
			utime.insert(std::pair<unsigned int, std::string>(counter, elapsed_utime()));
		}
		#pragma omp section
		{
			usage.insert(std::pair<unsigned int, std::string>(counter, elapsed_usage()));
		}
		#pragma omp section
		{
			stopped = true;
		}
	}
};
