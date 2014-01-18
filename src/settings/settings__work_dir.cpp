//
//
//
inline std::string work_dir()
{
    switch(work_dir_manager.file_system::exists() and 
           work_dir_manager.file_system::is_dir())
    {
        case false: return ""; break;
        case  true: return work_dir_manager.file_system::full_name(); break;
    }
};
