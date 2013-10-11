//
//
//
inline void write_title_bar(std::string given_title, unsigned int given_size)
{
    if(log_file_ready)
    {
        std::string stamp = timestamp();
        if(given_size > stamp.length() + given_title.length() + 1) 
        {
            log_file << "\n";
            given_size -= stamp.length() + given_title.length() + 1; 
            log_file << stamp << given_title << " ";
            log_file.width(given_size);
            log_file.fill(TITLE_BAR_SYMBOL);
            log_file << "\n";
            log_file << std::endl;
        }
        else
        {
            log_file << "\n";
            log_file << stamp << given_title;
            log_file << "\n";
            log_file << std::endl;
        }
    }
};
