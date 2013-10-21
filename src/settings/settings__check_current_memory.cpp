// ../src/settings/settings__check_current_memory.cpp ---------------------------------- //
//
// File author: Humberto Jr. 
//
// Date: 06/2013
//
// Description: The settings's member to check the current available memory 
//              and the total memory in kB. This function may or may not be 
//              system-dependent. In such case the implementation should 
//              come enclosed between the respective OS macro. So far the 
//              Linux version just checks the /proc/meminfo file, since the
//              libraries that handle such task seems do not behave well.
//
// References:
//
// ------------------------------------------------------------------------------------- //
//
//
//
#ifdef LINUX
inline std::string check_current_memory(const int option)
{
    switch(option)
    {
        case 1:
        { 
            std::ifstream user_config_file(LINUX_MEMINFO_FILE, std::ios::in);         // (1)
            if(user_config_file.is_open() and user_config_file.good())                // (2)
            {
                std::string line = "";
                while(getline(user_config_file, line))                                // (3)
                {
                    if(line.compare(0, 9, "MemTotal:") == 0)                          // (7)
                    {
                        std::istringstream string_value(line.erase(0, 15));
                        return line;                                                  // (8)
                    }
                }
                user_config_file.close();
                return "0.0 Kb";                                                      // (9) 
            }
            else
            {
                return "0.0 Kb";                                                      // (10)
            }
        }
        break;
        case 2:
        {
            std::ifstream user_config_file(LINUX_MEMINFO_FILE, std::ios::in);
            if(user_config_file.is_open() and user_config_file.good())
            {
                std::string line = "";
                while(getline(user_config_file, line))
                {
                    if(line.compare(0, 8, "MemFree:") == 0)
                    {
                        std::istringstream string_value(line.erase(0, 15));
                        return line;
                    }
                }
                user_config_file.close();
                return "0.0 Kb";
            }
            else
            {
                return "0.0 Kb";
            }
        }
        break;
        default: return "0.0 Kb";
    }
};
#endif
