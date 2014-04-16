//
//
//
/// @brief Checks if the current path (either of a directory or a file) exists.
//
/// @return @c true if the path exists, and @c false otherwise.
//
inline bool exists()
{
	return boost::filesystem::exists(file_status);
};
