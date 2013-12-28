//
//
//
inline void set_right()
{
    switch(log_file_ready)
    {
        case  true:
        log_file.std::fstream::fill(' ');
        log_file << std::right;
        break;
    }
};
