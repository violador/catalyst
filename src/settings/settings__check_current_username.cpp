//
//
//
/// @brief Returns the current username from the enviroment variable.
//
/// @return A string pattern.
//
inline std::string check_current_username()
{
//
//  The Linux version:
	#if defined(LINUX)
	return tools::convert<std::string>(getenv("LOGNAME"));
	#endif
//
//  The Microsoft Windows version:
	#if defined(WIN32)
	return "";
	#endif
//
//  The Apple OS-X version:
	#if defined(OS_X)
	return "";
	#endif
};
