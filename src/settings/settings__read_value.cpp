//
//
//
template<typename data_type>
data_type read_value(const std::string &option,
                     const int &option_length,
                     const unsigned int &default_value)
{
//  (1) To open the user's config file.
//  (2) To check if the file is open and ok.
//  (3) To read a line from the file.
//  (4) To avoid comment lines tagged with '#'.
//  (5) To remove blank spaces. 
//  (6) To turn all chars into lowercase.
//  (7) To check the pattern option. 
//  (8) To return the std::string number converted to data_type.
//  (9) If no pattern option is found: Setup the default value.
    std::ifstream file(config_file.std::string::c_str(), std::ios::in);                 // (1)
    switch(file.std::ifstream::is_open() and file.std::ifstream::good())                // (2) 
    {
        case false:
        {
            return default_value;
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
                    tools::lower_case(line);                                           // (6) 
                    switch((bool) line.std::string::compare(0, option_length, option)) // (7)
                    {
                        case false:
                        return tools::convert<data_type>(line.std::string::erase(0, option_length)); // (8)
                        break;
                    }
                    break;
                }
            }
            file.std::ifstream::close();
            return default_value;                                                      // (9)
        }
        break;
    }
}
