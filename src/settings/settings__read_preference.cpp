#include "settings.hpp"
//
//
//  Defining the settings member function to read the user's config file 
//  and to get the user's preference in a given pattern option:
std::string settings::read_preference(const std::string option,
                                      const int option_length,
                                      const std::string default_preference)
{
//  1)  To open the user's config file.
//  2)  To check if the file is open and ok.
//  3)  To read a line from the file.
//  4)  To avoid comment lines tagged with '#'.
//  5)  To remove blank spaces. 
//  6)  To turn all chars into lowercase.
//  7)  To check the pattern option. 
//  8)  To return the line without the pattern option, i.e. the user's preference.
//  9)  If no pattern option is found: Setup the default preference.
//  10) If the user's config file is not open or not ok: Setup the default preference. 
    std::ifstream user_config_file(USER_CONFIG_FILENAME, std::ios::in);                                    // (1)
    if(user_config_file.is_open() && user_config_file.good())                                              // (2)
    {
        std::string line = "";
        while(getline(user_config_file, line))                                                             // (3)
        {
            if(line.compare(0, 1, COMMENT_TAG) != 0)                                                       // (4)
            {
                line.erase(remove(line.begin(), line.end(), ' '), line.end());                             // (5)
                std::transform(line.begin(), line.end(), line.begin(), std::ptr_fun(tolower));             // (6)
                if(line.compare(0, option_length, option) == 0)                                            // (7)
                {
                    return line.erase(0, option_length);                                                   // (8)
                }
            }
        }
        user_config_file.close();
        return default_preference;                                                                         // (9) 
    }
    else
    {
        std::cout << "ERROR: User's config file file not found! Setting up default values." << std::endl;
        return default_preference;                                                                         // (10)
    }
}
