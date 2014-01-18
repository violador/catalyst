//
//
//
inline std::string scratch_dir()
{
    switch(scratch_dir_manager.file_system::exists() 
           and scratch_dir_manager.file_system::is_dir())
    {
        case false: return ""; break;
        case  true: return scratch_dir_manager.file_system::full_name(); break;
    }
};
