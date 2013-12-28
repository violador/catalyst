//
//
//
inline std::string dir_path_of(const unsigned int option)
{
    switch(option)
    {
        case option::scratch: return scratch_dir; break;
        case    option::work: return work_dir;    break;
                     default: return "";
    }
};
