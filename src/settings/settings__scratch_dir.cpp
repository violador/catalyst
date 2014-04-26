//
//
//
/// @brief Returns the full path of the scratch directory if it exists and is a
///        directory indeed. Otherwise returns an empty string.
//
/// @return A string pattern.
//
inline std::string scratch_dir()
{
	switch(scratch_dir_manager.file_system::exists()
	       && scratch_dir_manager.file_system::is_dir())
	{
		case true:
		return scratch_dir_manager.file_system::full_name();
	}
	return "";
};
