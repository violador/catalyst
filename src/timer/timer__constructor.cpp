// ../src/timer/timer__constructor.cpp ====================================================== //
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
timer::timer(): stopped(true),
				timer_length(10),
				counter(0),
				name(""),
				config(&global_settings::config)
{
// Empty constructor.
}
//
//
//
timer::timer(std::string &given_name): stopped(true),
									   timer_length(10),
									   counter(0),
									   name(given_name),
									   config(&global_settings::config)
{
// Empty constructor.
}
