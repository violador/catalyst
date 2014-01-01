//
//
//
inline void rename_dir(const std::string &new_name)
{
    boost::filesystem::rename(path, new_name);
    restart_path(new_name);
};
