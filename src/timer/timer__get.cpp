// ../src/timer/timer__get.cpp ============================================================== //
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
std::string timer::get(unsigned int option, 
                       unsigned int measurement_number)
{
    if((measurement_number > 0) and (measurement_number <= counter))
    {
        switch(option)
        {
            case   WALL_TIME: return wall_time[measurement_number];   break;
            case SYSTEM_TIME: return system_time[measurement_number]; break;
            case   USER_TIME: return user_time[measurement_number];   break;
            case   CPU_USAGE: return cpu_usage[measurement_number];   break;
            case  TIMER_NAME: return name; break;
                     default: return "";
        }
    }
    else
    {
        measurement_number = counter;
        switch(option)
        {
            case   WALL_TIME: return wall_time[measurement_number];   break;
            case SYSTEM_TIME: return system_time[measurement_number]; break;
            case   USER_TIME: return user_time[measurement_number];   break;
            case   CPU_USAGE: return cpu_usage[measurement_number];   break;
            case  TIMER_NAME: return name; break;
                     default: return "";
        }
    }
}