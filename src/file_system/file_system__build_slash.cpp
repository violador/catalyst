//
//
//
/// @brief A help function that builds on-the-fly the
///        slash "/" or "\" depending the current OS.
//
/// @return A string pattern.
//
inline std::string build_slash() const
{
	#if defined(LINUX)
	return std::string("/");
	#elif defined(WIN32)
	return std::string("\\");
	#endif
};
