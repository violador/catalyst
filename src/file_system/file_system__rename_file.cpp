//
//
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
