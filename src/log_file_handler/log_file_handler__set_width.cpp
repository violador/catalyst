//
//
//
inline void set_width(unsigned int given_width)
{
    switch(log_file_ready)
    {
        case false: break;
        case  true: log_file.width(given_width); break;
    }
};
