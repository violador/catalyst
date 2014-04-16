//
//
//
/// @brief Returns the current number of CPUs available.
//
/// @return A non-negative integer.
//
inline unsigned int check_current_cpus()
{
	#if defined(LINUX)
	return sysconf(_SC_NPROCESSORS_CONF);
	#endif
};
