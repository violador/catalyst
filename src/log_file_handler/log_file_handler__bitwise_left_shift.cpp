//
//
//
template<typename data_type> 
inline void operator <<(const data_type &data)
{
    switch(config -> output_mode() and log_file_ready)
    {
        case true: log_file << data; break;
    }
};
