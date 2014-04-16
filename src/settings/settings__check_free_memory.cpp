#include "settings.hpp"
//
//
//
/// @brief Returns the current free RAM memory in gigabytes.
//
/// @return A non-negative real number.
//
double settings::check_free_memory()
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
				switch(tools::is_equal("MemFree:", line))
				{
					case true:
					tools::remove_blank_spaces(line);
					tools::remove_char(line, 'k');
					tools::remove_char(line, 'B');
					tools::remove(line, 0, 8);
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
