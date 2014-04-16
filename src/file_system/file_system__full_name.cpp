//
//
//
/// @brief Returns the full name of the current path (either
///        of a directory or a file).
//
/// @return A string pattern.
//
inline std::string full_name()
{
	return root_path.boost::filesystem::path::string()
			+ relative_path.boost::filesystem::path::string();
};
