//
//
//
/// @brief Returns the full path of the work directory if it exists and is a directory
///        indeed. Otherwise returns an empty string.
//
/// @return A string pattern.
//
inline std::string work_dir()
{
	switch(work_dir_manager.file_system::exists()
	       && work_dir_manager.file_system::is_dir())
	{
		case true:
		return work_dir_manager.file_system::full_name();
	}
	return "";
};
