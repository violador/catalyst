//
//
//
inline void close()
{
    if(log_file_ready)
    {
        log_file.close();
        log_file_ready = false;
    }
};
