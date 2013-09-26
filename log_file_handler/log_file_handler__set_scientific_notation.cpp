//
//
//
inline void set_scientific_notation(unsigned int given_width = MAX_PRECISION + SPACE_LENGTH)
{
    if(log_file_ready)
    {
        log_file << std::scientific;
        log_file.width(given_width);
        log_file.precision(config -> numeric_precision());
        log_file << std::right;
    }
};
