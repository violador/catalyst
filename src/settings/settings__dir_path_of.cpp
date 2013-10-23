//
//
//
inline std::string dir_path_of(const unsigned int option)
{
    switch(option)
    {
        case SCRATCH: return scratch_dir; break;
        case    WORK: return work_dir;    break;
             default: return "";
    }
};
