#include "settings.hpp"
//
//
//
bool settings::read_state(const std::string option,
                          const std::string state,
                          const int option_length,
                          const int state_length,
                          bool default_state)
{
//  1)  To open the user's config file.
//  2)  To check if the file is open and ok.
//  3)  To read a line from the file.
//  4)  To avoid comment lines tagged with '#'.
//  5)  To remove blank spaces. 
//  6)  To turn all chars into lowercase.
//  7)  To check the pattern option. 
//  8)  To check the pattern state.
//  9)  If no pattern option is found: Setup the default state.
//  10) If the user's config file is not open or not ok: Setup the default state.
    std::ifstream user_config_file(USER_CONFIG_FILENAME, std::ios::in);                        // (1)
    if(user_config_file.is_open() && user_config_file.good())                                  // (2) 
    {
        std::string line = "";
        while(getline(user_config_file, line))                                                 // (3)
        {
            if(line.compare(0, 1, COMMENT_TAG))                                                // (4)
            {
                line.erase(remove(line.begin(), line.end(), ' '), line.end());                 // (5)
                std::transform(line.begin(), line.end(), line.begin(), std::ptr_fun(tolower)); // (6)
                if(not line.compare(0, option_length, option))                                 // (7)
                {
                    if(not line.compare(option_length, state_length, state))                   // (8)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        user_config_file.close();
        return default_state;                                                                  // (9)
    }
    else
    {
        return default_state;                                                                  // (10)
    }
}
