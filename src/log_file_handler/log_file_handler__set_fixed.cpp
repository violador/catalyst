//
//
//
inline void set_fixed()
{
    switch(log_file_ready)
    {
        case true:
        log_file.std::fstream::precision(config -> numeric_precision());
        log_file << std::fixed;
        break;
    }
};
