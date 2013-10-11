//
//
//
template<typename data_type> inline void operator <<(const data_type &given_data)
{
    if(config -> state_of(OUTPUT_MODE) and log_file_ready)
    {
        log_file << given_data;
    }
};
