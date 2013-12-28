//
//
//
inline std::string timestamp() 
{
    #ifdef USE_OMP
//
    time_t current_time = time(0);
    struct tm *time_info;
    time_info = localtime(&current_time);
    char timestamp[12];
    strftime(timestamp, 12, ", %T]", time_info);
    return "[thread " + tools::convert<std::string>(omp_get_thread_num()) 
                      + tools::convert<std::string>(timestamp) 
                      + " ";
//
    #elif USE_MPI
//
//  Empty so far.
//
    #else
//
    time_t current_time = time(0);
    struct tm *time_info;
    time_info = localtime(&current_time);
    char timestamp[11];
    strftime(timestamp, 11, "[%T]", time_info);
    return tools::convert<std::string>(timestamp) + " ";
//
    #endif
};
