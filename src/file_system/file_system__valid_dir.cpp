//
//
//
/// @brief Checks if the current directory exists and is a directory indeed.
//
/// @return @c true if the directory is valid, and @c false otherwise.
//
inline bool valid_dir()
{
	return bool(boost::filesystem::exists(path_status)
				and boost::filesystem::is_directory(path_status));
};
