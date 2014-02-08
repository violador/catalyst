// ../src/timer/timer__basic_assignment.cpp ================================================= //
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
//
//
//
/// @param [in] input Another previously declared @c timer object
//
/// @brief The operator @c = will copy the content of the given @c
///        input to the current object.
//
/// @return None.
//
inline void operator =(const timer &input)
{
	#pragma omp parallel sections num_threads(7)
	{
		#pragma omp section
		{
			this -> config = input.config;
		}
		#pragma omp section
		{
			this -> wall_time = input.wall_time;
		}
		#pragma omp section
		{
			this -> system_time = input.system_time;
		}
		#pragma omp section
		{
			this -> user_time = input.user_time;
		}
		#pragma omp section
		{
			this -> cpu_usage = input.cpu_usage;
		}
		#pragma omp section
		{
			this -> name = input.name;
		}
	}
};
