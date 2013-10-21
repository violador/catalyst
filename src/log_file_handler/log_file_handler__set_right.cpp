//
//
//
inline void set_right()
{
    switch(log_file_ready)
    {
        case false: break;
        case  true:
        {
            log_file.fill(' ');
            log_file << std::right;
        }
        break;
    }
};
