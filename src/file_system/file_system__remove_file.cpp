//
//
//
inline void remove_file()
{
    switch(is_file())
    {
        case true:
        boost::filesystem::remove(file);
        restart_file(parent_dir() + build_slash(), "");
        break;
    }
};
