//
//
//
inline void fill_line_with(const unsigned int width, 
                           const std::string text)
{
    switch(log_file_ready)
    {
        case true:
        log_file.std::fstream::width(width);
        log_file.std::fstream::fill(tools::convert<char>(text));
        log_file << "";
        break;
    }
};
//
//
//
inline void fill_line_with(const unsigned int width)
{
    switch(log_file_ready)
    {
        case true:
        log_file.std::fstream::width(width);
        log_file.std::fstream::fill(' ');
        log_file << "";
        break;
    }
};
