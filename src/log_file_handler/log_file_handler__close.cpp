//
//
//
inline void close()
{
    switch(log_file_ready)
    {
        case false: break;
        case  true:
        {
            log_file.close();
            log_file_ready = false;
        }
        break;
    }
};
