//
//
//
inline std::string filename_of(const unsigned int option)
{
    switch(option)
    {    
        case 1: return log_filename;         break;
        case 2: return input_filename[0];    break;
        case 3: return USER_CONFIG_FILENAME; break;
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
        case 1: return log_filename;                break;
        case 2: return input_filename[task_number]; break;
        case 3: return USER_CONFIG_FILENAME;        break;
       default: return DEFAULT_NO_FILENAME;
    }    
};
