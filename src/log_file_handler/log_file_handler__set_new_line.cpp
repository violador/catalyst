//
//
//
inline void set_new_line()
{
    switch(log_file_ready)
    {
        case false: break;
        case  true: log_file << std::endl; break;
    }
};
