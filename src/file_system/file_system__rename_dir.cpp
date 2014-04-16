//
//
//
/// @param [in] new_name A string pattern with the new directory name.
//
/// @brief Renames the current directory and updates the internal data.
//
/// @return None.
//
inline void rename_dir(const std::string &new_name)
{
	boost::filesystem::rename(path, new_name);
	restart_path(new_name);
};
