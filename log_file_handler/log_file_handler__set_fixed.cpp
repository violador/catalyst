//
//
//
inline void set_fixed()
{
    if(log_file_ready)
    {
        log_file.precision(config -> numeric_precision());
        log_file << std::fixed;
    }
};
