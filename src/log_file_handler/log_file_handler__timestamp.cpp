//
//
//
/// @brief Generates a timestamp in the logfile that provide informations
///        about the current thread (if OMP is enabled) or current process
///        (if MPI is enabled) and the current time.
//
/// @return None.
//
inline std::string timestamp()
{
	#if defined(USE_OMP)
	current_time = time(0);
	time_info = localtime(&current_time);
	strftime(stamp, 12, ", %T]", time_info);
	return "[thread " + tools::convert<std::string>(omp_get_thread_num())
	       + std::string(stamp)
	       + " ";
	#else
	current_time = time(0);
	time_info = localtime(&current_time);
	strftime(stamp, 11, "[%T]", time_info);
	return std::string(stamp) + " ";
	#endif
};
