//
//
//
inline void set_scientific_notation(const unsigned int &width)
{
    switch(log_file_ready)
    {
        case true:
        log_file << std::scientific;
        log_file.std::fstream::width(width);
        log_file.std::fstream::precision(config -> numeric_precision());
        log_file << std::right;
        break;
    }
};
//
//
//
inline void set_scientific_notation()
{
    switch(log_file_ready)
    {
        case true:
        log_file << std::scientific;
        log_file.std::fstream::width(MAX_PRECISION + SPACE_LENGTH);
        log_file.std::fstream::precision(config -> numeric_precision());
        log_file << std::right;
        break;
    }
};
