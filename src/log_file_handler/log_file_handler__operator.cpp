//
//
//
template<typename data_type> 
inline void operator <<(const data_type &given_data)
{
    switch(config -> state_of(OUTPUT_MODE) and log_file_ready)
    {
        case true:
        log_file << given_data;
        break;
    }
};
