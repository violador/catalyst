//
//
//
inline void write_title_bar(std::string title, 
                            unsigned int size)
{
    switch(log_file_ready)
    {
        case true:
        std::string stamp = timestamp();
        if(size > stamp.std::string::length() + title.std::string::length() + 1) 
        {
            log_file << "\n";
            size -= stamp.std::string::length() + title.std::string::length() + 1; 
            log_file << stamp << title << " ";
            log_file.std::fstream::width(size);
            log_file.std::fstream::fill(TITLE_BAR_SYMBOL);
            log_file << "\n";
            log_file << std::endl;
        }
        else
        {
            log_file << "\n";
            log_file << stamp << title;
            log_file << "\n";
            log_file << std::endl;
        }
        break;
    }
};
