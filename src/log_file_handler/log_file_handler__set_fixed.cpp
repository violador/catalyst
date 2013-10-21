//
//
//
inline void set_fixed()
{
    switch(log_file_ready)
    {
        case false: break;
        case  true:
        {
            log_file.precision(config -> numeric_precision());
            log_file << std::fixed;
        }
        break;
    }
};
