//
//
//
/// @brief Checks if the current path is of a file.
//
/// @return @c true if it is a file, and @c false otherwise.
//
inline bool is_file()
{
	return boost::filesystem::is_regular_file(file_status);
};
