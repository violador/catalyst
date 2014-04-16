//
//
//
/// @param [in] new_name A string pattern with the new file name.
//
/// @brief Renames the current file and updates the internal data.
//
/// @return None.
//
inline void rename_file(const std::string &new_name)
{
	switch(is_file())
	{
		case true:
		boost::filesystem::rename(file, parent_dir() + build_slash() + new_name);
		restart_file(parent_dir() + build_slash(), new_name);
		break;
	}
};
