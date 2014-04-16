//
//
//
/// @brief Checks if the current path is of a directory.
//
/// @return @c true if it is a directory, and @c false otherwise.
//
inline bool is_dir()
{
	return boost::filesystem::is_directory(file_status);
};
