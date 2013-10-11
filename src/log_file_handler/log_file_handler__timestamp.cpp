//
//
//
inline std::string timestamp() 
{
    #ifdef USE_OMP
//
    tools convert;
    time_t current_time = time(0);
    struct tm *time_info;
    time_info = localtime(&current_time);
    char timestamp[12];
    strftime(timestamp, 12, ", %T]", time_info);
    return "[thread " + convert.to_string_from(omp_get_thread_num()) + convert.to_string_from(timestamp) + " ";
//
    #elif USE_MPI
//
//  Empty so far.
//
    #else
//
    tools convert;
    time_t current_time = time(0);
    struct tm *time_info;
    time_info = localtime(&current_time);
    char timestamp[11];
    strftime(timestamp, 11, "[%T]", time_info);
    return convert.to_string_from(timestamp) + " ";
//
    #endif
};
