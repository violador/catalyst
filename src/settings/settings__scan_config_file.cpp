// ../src/settings/settings__scan_config_file.cpp ------------------------------------------- //
//
//  This file is part of Catalyst lib.
//
//  Catalyst lib is free software: you can redistribute it and/or modify it under the terms 
//  of the GNU General Public License as published by the Free Software Foundation, either 
//  version 3 of the License, or (at your option) any later version.
//
//  Catalyst lib is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
//  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
//  See the GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License along with Catalyst lib. 
//  If not, see <http://www.gnu.org/licenses/>.
//
// ------------------------------------------------------------------------------------------ //
#include "settings.hpp"
//
//
//
/// @author Humberto Jr. 
//
/// @date 05/2013
//
/// @return The @c int key found before the given @c option in the config file,
///         Otherwise, return the given @c default_preference. The search pattern
///         @c option @c = @c key.
//
/// @cite
//
int settings::scan_config_file(const std::string &option,
                               const int &default_key)
{
//
/// @note This member function reads the entire config file looking for the pattern
///       @c option @c = @c key. It ignores the existence of blank space by removing 
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
/// @author Humberto Jr. 
//
/// @date 05/2013
//
/// @return The @c double key found before the given @c option in the config file.
///         Otherwise, return the given @c default_preference. The search pattern
///         @c option @c = @c key.
//
/// @cite
//
double settings::scan_config_file(const std::string &option,
                                  const double &default_key)
{
//
/// @note This member function reads the entire config file looking for the pattern
///       @c option @c = @c key. It ignores the existence of blank space by removing 
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
/// @author Humberto Jr. 
//
/// @date 05/2013
//
/// @return The @c std::string key found before the given @c option in the config 
///         file. Otherwise, return the given @c default_preference. The search 
///         pattern @c option @c = @c key.
//
/// @cite
//
std::string settings::scan_config_file(const std::string &option,
                                       const std::string &default_key)
{
//
/// @note This member function reads the entire config file looking for the pattern
///       @c option @c = @c key. It ignores the existence of blank space by removing 
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
///      scan_config_file(option, @c (std::string) @c "my default input key");.
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
/// @author Humberto Jr. 
//
/// @date 05/2013
//
/// @return The @c bool key found before the given @c option in the config file.
///         Otherwise, return the given @c default_preference. The search pattern
///         @c option @c = @c key.
//
/// @cite
//
bool settings::scan_config_file(const std::string &option,
                                const bool &default_key)
{
//
/// @note This member function reads the entire config file looking for the pattern
///       @c option @c = @c key. It ignores the existence of blank space by removing 
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
