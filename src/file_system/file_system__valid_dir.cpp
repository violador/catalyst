//
//
//
inline bool valid_dir()
{
    switch(boost::filesystem::exists(path_status) 
           and boost::filesystem::is_directory(path_status))
    {
        case false: return false; break;
        case  true: return  true; break;
    }
};
