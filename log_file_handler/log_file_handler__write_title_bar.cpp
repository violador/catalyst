//
//
//
inline void write_title_bar(std::string given_title, unsigned int given_size)
{
    if(log_file_ready)
    {
        if(given_size > given_title.length() + 4) 
        {
            given_size -= given_title.length() + 4; 
            log_file << "\n";
            log_file << TITLE_BAR_SYMBOL;
            log_file << TITLE_BAR_SYMBOL;
            log_file << " " << given_title << " ";
            log_file.width(given_size);
            log_file.fill(TITLE_BAR_SYMBOL);
            log_file << "\n";
            log_file << std::endl;
        }
        else
        {
            log_file << "\n";
            log_file << TITLE_BAR_SYMBOL;
            log_file << TITLE_BAR_SYMBOL;
            log_file << " " << given_title;
            log_file << "\n";
            log_file << std::endl;
        }
    }
};
