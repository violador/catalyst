//
//
//
inline void fill_line_with(unsigned int given_width, std::string given_text = " ")
{
    if(log_file_ready)
    {
        std::istringstream converter(given_text);
        char converted_text;
        converter >> converted_text;
        log_file.width(given_width);
        log_file.fill(converted_text);
    }
};
