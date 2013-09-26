//
//
//
inline void set_left()
{
    if(log_file_ready)
    {
        log_file.fill(' ');
        log_file << std::left;
    }
};
