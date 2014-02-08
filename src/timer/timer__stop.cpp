// ../src/timer/timer__stop.cpp ============================================================= //
//
// Catalyst Lib is free software:  you can redistribute it and/or modifyit under the terms of
// the GNU General Public License as published bythe Free Software Foundation, either version
// 3 of the License, or(at your option) any later version.
//
// Catalyst Lib is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
// without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with Catalyst Lib.
// If not, see <http://www.gnu.org/licenses/>.
//
// ========================================================================================== //
#include "timer.hpp"
//
//
//
/// @brief Stops the time elapsed measurement if it was started.
//
/// @return None.
//
/// @cite boost
//
void timer::stop()
{
	switch(stopped)
	{
		case false:
		chronometer.boost::timer::cpu_timer::stop();
		#pragma omp parallel sections num_threads(5)
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
