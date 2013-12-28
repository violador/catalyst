//
//
//
inline void close()
{
    switch(log_file_ready)
    {
        case  true:
        file_manager -> close(log_file);
        log_file_ready = false;
        break;
    }
};
