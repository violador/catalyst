#include "settings.hpp"
//
//
//
/// @brief The @c int key found before the given @c option in the config file,
///        Otherwise, return the given @c default_preference. The search pattern
///        @c "option = key".
//
/// @return An integer number.
//
int settings::scan_config_file(const std::string &option,
							   const int &default_key)
{
//
/// @note This member function reads the entire config file looking for the pattern
///       @c "option = key". It ignores the existence of blank space by removing
///       them. In the other hand, it is case sensitive (since it is also used to
///       read paths).
//
	std::ifstream file(config_file.std::string::c_str(), std::ios::in);
	switch(file.std::ifstream::is_open() and file.std::ifstream::good())
	{
		case false:
		{
			return default_key;
		}
		break;
		case true:
		{
			std::string line = "";
			while(getline(file, line))
			{
				switch(tools::comment_line(line))
				{
					case false:
					tools::remove_blank_spaces(line);
					switch(tools::is_equal(option, line))
					{
						case true:
						remove_option(line, option);
						return tools::convert<int>(line);
						break;
					}
					break;
				}
			}
			file.std::ifstream::close();
			return default_key;
		}
		break;
	}
}
//
//
//
/// @brief The @c double key found before the given @c option in the config file.
///        Otherwise, return the given @c default_preference. The search pattern
///        @c "option = key".
//
/// @return A real number.
//
double settings::scan_config_file(const std::string &option,
								  const double &default_key)
{
//
/// @note This member function reads the entire config file looking for the pattern
///       @c "option = key". It ignores the existence of blank space by removing
///       them. In the other hand, it is case sensitive (since it is also used to
///       read paths).
//
	std::ifstream file(config_file.std::string::c_str(), std::ios::in);
	switch(file.std::ifstream::is_open() and file.std::ifstream::good())
	{
		case false:
		{
			return default_key;
		}
		break;
		case true:
		{
			std::string line = "";
			while(getline(file, line))
			{
				switch(tools::comment_line(line))
				{
					case false:
					tools::remove_blank_spaces(line);
					switch(tools::is_equal(option, line))
					{
						case true:
						remove_option(line, option);
						return tools::convert<double>(line);
						break;
					}
					break;
				}
			}
			file.std::ifstream::close();
			return default_key;
		}
		break;
	}
}
//
//
//
/// @brief The @c std::string key found before the given @c option in the config
///        file. Otherwise, return the given @c default_preference. The search
///        pattern @c "option = key".
//
/// @return A string pattern.
//
std::string settings::scan_config_file(const std::string &option,
									   const std::string &default_key)
{
//
/// @note This member function reads the entire config file looking for the pattern
///       @c "option = key". It ignores the existence of blank space by removing
///       them. In the other hand, it is case sensitive (since it is also used to
///       read paths).
//
/// @bug Since this is an overloaded function, the compiler needs to know the proper version
///      of the function to call (through the second input argument). The type promotion did
///      also by the compiler may or may not induce it to call the wrong one. The only known
///      case so far is for the @c std::string type: When the @c std::string @c default_key
///      argument is given in terms of quote symbols, @c " ", i.e. @c const @c char*, the
///      compiler can convert it to @c int type (@c char, @c size_t, and @c bool may bahave
///      as @c int). Due to that, the function called will be the @c int type one. To avoid
///      this problem, when the second input argument is given by means of quote symbols, it
///      is highly recomended to specify its type. The layout call should looks like @c
///      "scan_config_file(option, (std::string) my_default_input_key)";.
//
	std::ifstream file(config_file.std::string::c_str(), std::ios::in);
	switch(file.std::ifstream::is_open() and file.std::ifstream::good())
	{
		case false:
		{
			return default_key;
		}
		break;
		case true:
		{
			std::string line = "";
			while(getline(file, line))
			{
				switch(tools::comment_line(line))
				{
					case false:
					tools::remove_blank_spaces(line);
					switch(tools::is_equal(option, line))
					{
						case true:
						remove_option(line, option);
						return line;
						break;
					}
					break;
				}
			}
			file.std::ifstream::close();
			return default_key;
		}
		break;
	}
}
//
//
//
/// @brief The @c bool key found before the given @c option in the config file.
///        Otherwise, return the given @c default_preference. The search pattern
///        @c "option = key".
//
/// @return @c true if "on", and @c false otherwise.
//
bool settings::scan_config_file(const std::string &option,
								const bool &default_key)
{
//
/// @note This member function reads the entire config file looking for the pattern
///       @c "option = key". It ignores the existence of blank space by removing
///       them. In the other hand, it is case sensitive (since it is also used to
///       read paths).
//
	std::ifstream file(config_file.std::string::c_str(), std::ios::in);
	switch(file.std::ifstream::is_open() and file.std::ifstream::good())
	{
		case false:
		{
			return default_key;
		}
		break;
		case true:
		{
			std::string line = "";
			while(getline(file, line))
			{
				switch(tools::comment_line(line))
				{
					case false:
					tools::remove_blank_spaces(line);
					switch(tools::is_equal(option, line))
					{
						case true:
						remove_option(line, option);
						return tools::is_equal(tools::on_ctrl_key(), line);
						break;
					}
					break;
				}
			}
			file.std::ifstream::close();
			return default_key;
		}
		break;
	}
}
