//
//
//
/// @brief Returns the current host ID.
//
/// @return An integer number.
//
inline int check_current_hostname()
{
//
//  The Linux version:
	#if defined(LINUX)
	return gethostid();
	#endif
//
//  The Microsoft Windows version:
	#if defined(WIN32)
	return 0;
	#endif
//
//  The Apple OS-X version:
	#if defined(OS_X)
	return 0;
	#endif
};
