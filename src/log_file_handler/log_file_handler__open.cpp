//
//
//
inline void open()
{
    manager.file_system::open_txt_output(log_file);
    switch(manager.file_system::is_open())
    {
        case true: log_file_ready = true; break;
    }
};
