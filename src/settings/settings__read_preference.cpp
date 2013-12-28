#include "settings.hpp"
//
//
//
std::string settings::read_preference(const std::string option,
                                      const int option_length,
                                      const std::string default_preference)
{
//
//  (1) To open the user's config file.
//  (2) To check if the file is open and ok.
//  (3) To read a line from the file.
//  (4) To avoid comment lines tagged with '#'.
//  (5) To remove blank spaces. 
//  (6) To check the pattern option. 
//  (7) To return the line without the pattern option, i.e. the user's preference.
//  (8) If no pattern option is found: Setup the default preference.
    std::ifstream file(config_file.std::string::c_str(), std::ios::in);                // (1)
    switch(file.std::ifstream::is_open() and file.std::ifstream::good())               // (2)
    {
        case false:
        {
            return default_preference;
        }
        break;
        case true:
        {
            std::string line = "";
            while(getline(file, line))                                                 // (3)
            {
                switch((bool) line.std::string::compare(0, 1, COMMENT_TAG))            // (4)
                {
                    case true:
                    tools::remove_blank_spaces(line);                                  // (5)
                    switch((bool) line.std::string::compare(0, option_length, option)) // (6)
                    {
                        case false:
                        return line.std::string::erase(0, option_length);              // (7)
                        break;
                    }
                    break;
                }
            }
            file.std::ifstream::close();
            return default_preference;                                                 // (8) 
        }
        break;
    }
}
