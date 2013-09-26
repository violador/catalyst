//
//
//
inline void set_right()
{
    if(log_file_ready)
    {
        log_file.fill(' ');
        log_file << std::right;
    }
};
