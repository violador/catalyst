//
//
//
inline char* check_current_time()
{
    time_t current_time = time(0);
    return ctime(&current_time);
};
