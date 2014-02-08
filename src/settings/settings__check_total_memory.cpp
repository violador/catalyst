// ../src/settings/settings__check_total_memory.cpp ========================================= //
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
#include "settings.hpp"
//
//
//
/// @brief Returns the current total RAM memory in gigabytes.
//
/// @return A non-negative real number.
//
double settings::check_total_memory()
{
//
/// @note The Linux version of this member function uses the @c /proc/meminfo
///       file to read the memory information. Make sure to have this file
///       located properly in the @c LINUX_MEMINFO_FILE macro in the @c
///       globals.hpp.
//
/// @warning So far there is no Microsoft Windows nor Apple OS-X versions
///          implemented for this member.
//
	std::ifstream file(LINUX_MEMINFO_FILE, std::ios::in);
	switch(file.std::ifstream::is_open() and file.std::ifstream::good())
	{
		case false:
		{
			return 0.0;
		}
		break;
		case true:
		{
			std::string line = "";
			while(getline(file, line))
			{
				switch(tools::is_equal("MemTotal:", line))
				{
					case true:
					tools::remove_blank_spaces(line);
					tools::remove_char(line, 'k');
					tools::remove_char(line, 'B');
					tools::remove(line, 0, 9);
					return tools::convert<double>(line)
							*tools::kilobyte_to_gigabyte();
					break;
				}
			}
			file.std::ifstream::close();
			return 0.0;
		}
		break;
	}
}
