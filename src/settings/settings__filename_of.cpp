//
//
//
inline std::string filename_of(const unsigned int option)
{
    switch(option)
    {    
        case    LOG_FILE: return log_filename;         break;
        case  INPUT_FILE: return input_filename[0];    break;
        case CONFIG_FILE: return USER_CONFIG_FILENAME; break;
                 default: return DEFAULT_NO_FILENAME;
    }    
};
//
//
//
inline std::string filename_of(const unsigned int option, unsigned int task_number)
{
    (task_number >= 1) and (task_number <= total_tasks)? --task_number : task_number = 0;
    switch(option)
    {    
        case    LOG_FILE: return log_filename;                break;
        case  INPUT_FILE: return input_filename[task_number]; break;
        case CONFIG_FILE: return USER_CONFIG_FILENAME;        break;
                 default: return DEFAULT_NO_FILENAME;
    }    
};
