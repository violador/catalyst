//
//
//
/// @brief Checks if the current path (either of a directory or of
///        a file) is a link.
//
/// @return @c true if it is a link, and @c false otherwise.
//
inline bool is_link()
{
	return boost::filesystem::is_symlink(file);
};
