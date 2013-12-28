//
//
//
inline std::string filename_of(const unsigned int option)
{
    switch(option)
    {    
        case    option::log_file: return log_filename;        break;
        case  option::input_file: return input_filename[0];   break;
        case option::config_file: return config_file;         break;
                         default: return DEFAULT_NO_FILENAME; break;
    }    
};
//
//
//
inline std::string filename_of(const unsigned int option, 
                               unsigned int task_number)
{
    (task_number >= 1) and (task_number <= total_tasks)? --task_number : task_number = 0;
    switch(option)
    {    
        case    option::log_file: return log_filename;                break;
        case  option::input_file: return input_filename[task_number]; break;
        case option::config_file: return config_file;                 break;
                         default: return DEFAULT_NO_FILENAME;         break;
    }    
};
