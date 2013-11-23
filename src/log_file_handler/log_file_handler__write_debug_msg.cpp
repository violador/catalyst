//
//
//
template<typename data_type1> 
void write_debug_msg(const data_type1 &text1)
{
    switch(config -> state_of(OUTPUT_MODE) 
           and config -> state_of(DEBUG_MODE) 
           and log_file_ready)
    {
        case true:
        #pragma omp critical
        log_file << timestamp() << "@" << text1 << std::endl;
        break;
    }
};
//
//
//
template<typename data_type1, 
         typename data_type2> 
inline void write_debug_msg(const data_type1 text1, 
                            const data_type2 text2)
{
    switch(config -> state_of(OUTPUT_MODE) 
           and config -> state_of(DEBUG_MODE) 
           and log_file_ready)
    {
        case true:
        #pragma omp critical
        log_file << timestamp() << "@" << text1
                                       << text2 << std::endl;
        break;
    }
};
//
//
//
template<typename data_type1, 
         typename data_type2, 
         typename data_type3>
inline void write_debug_msg(const data_type1 &text1, 
                            const data_type2 &text2, 
                            const data_type3 &text3)
{
    switch(config -> state_of(OUTPUT_MODE) 
           and config -> state_of(DEBUG_MODE) 
           and log_file_ready)
    {
        case true:
        #pragma omp critical
        log_file << timestamp() << "@" << text1 
                                       << text2 
                                       << text3 << std::endl;
        break;
    }
};
//
//
//
template<typename data_type1, 
         typename data_type2, 
         typename data_type3, 
         typename data_type4> 
inline void write_debug_msg(const data_type1 &text1, 
                            const data_type2 &text2, 
                            const data_type3 &text3, 
                            const data_type4 &text4)
{
    switch(config -> state_of(OUTPUT_MODE) 
           and config -> state_of(DEBUG_MODE) 
           and log_file_ready)
    {
        case true:
        #pragma omp critical
        log_file << timestamp() << "@" << text1 
                                       << text2 
                                       << text3 
                                       << text4 << std::endl;
        break;
    }
};
//
//
//
template<typename data_type1, 
         typename data_type2,
         typename data_type3,
         typename data_type4,
         typename data_type5> 
inline void write_debug_msg(const data_type1 &text1, 
                            const data_type2 &text2,
                            const data_type3 &text3, 
                            const data_type4 &text4,
                            const data_type5 &text5)
{
    switch(config -> state_of(OUTPUT_MODE) 
           and config -> state_of(DEBUG_MODE) 
           and log_file_ready)
    {
        case true:
        #pragma omp critical
        log_file << timestamp() << "@" << text1
                                       << text2 
                                       << text3 
                                       << text4 
                                       << text5 << std::endl;
        break;
    }
};
//
//
//
template<typename data_type1,
         typename data_type2,
         typename data_type3,
         typename data_type4,
         typename data_type5,
         typename data_type6> 
inline void write_debug_msg(const data_type1 &text1,
                            const data_type2 &text2,
                            const data_type3 &text3,
                            const data_type4 &text4,
                            const data_type5 &text5,
                            const data_type6 &text6)
{
    switch(config -> state_of(OUTPUT_MODE) 
           and config -> state_of(DEBUG_MODE) 
           and log_file_ready)
    {
        case true:
        #pragma omp critical
        log_file << timestamp() << "@" << text1
                                       << text2 
                                       << text3 
                                       << text4 
                                       << text5
                                       << text6 << std::endl;
        break;
    }
};
//
//
//
template<typename data_type1,
         typename data_type2,
         typename data_type3,
         typename data_type4,
         typename data_type5,
         typename data_type6,
         typename data_type7> 
inline void write_debug_msg(const data_type1 &text1,
                            const data_type2 &text2,
                            const data_type3 &text3,
                            const data_type4 &text4,
                            const data_type5 &text5,
                            const data_type6 &text6,
                            const data_type7 &text7)
{
    switch(config -> state_of(OUTPUT_MODE) 
           and config -> state_of(DEBUG_MODE) 
           and log_file_ready)
    {
        case true:
        #pragma omp critical
        log_file << timestamp() << "@" << text1
                                       << text2
                                       << text3
                                       << text4
                                       << text5
                                       << text6
                                       << text7 << std::endl;
        break;
    }
};
//
//
//
template<typename data_type1,
         typename data_type2,
         typename data_type3,
         typename data_type4,
         typename data_type5,
         typename data_type6,
         typename data_type7,
         typename data_type8> 
inline void write_debug_msg(const data_type1 &text1,
                            const data_type2 &text2,
                            const data_type3 &text3,
                            const data_type4 &text4,
                            const data_type5 &text5,
                            const data_type6 &text6,
                            const data_type7 &text7,
                            const data_type8 &text8)
{
    switch(config -> state_of(OUTPUT_MODE) 
           and config -> state_of(DEBUG_MODE) 
           and log_file_ready)
    {
        case true:
        #pragma omp critical
        log_file << timestamp() << "@" << text1
                                       << text2
                                       << text3
                                       << text4
                                       << text5
                                       << text6
                                       << text7
                                       << text8 << std::endl;
        break;
    }
};
//
//
//
template<typename data_type1,
         typename data_type2,
         typename data_type3,
         typename data_type4,
         typename data_type5,
         typename data_type6,
         typename data_type7,
         typename data_type8,
         typename data_type9> 
inline void write_debug_msg(const data_type1 &text1,
                            const data_type2 &text2,
                            const data_type3 &text3,
                            const data_type4 &text4,
                            const data_type5 &text5,
                            const data_type6 &text6,
                            const data_type7 &text7,
                            const data_type8 &text8,
                            const data_type9 &text9)
{
    switch(config -> state_of(OUTPUT_MODE) 
           and config -> state_of(DEBUG_MODE) 
           and log_file_ready)
    {
        case true:
        #pragma omp critical
        log_file << timestamp() << "@" << text1
                                       << text2
                                       << text3
                                       << text4
                                       << text5
                                       << text6
                                       << text7
                                       << text8
                                       << text9 << std::endl;
        break;
    }
};
//
//
//
template<typename data_type1,
         typename data_type2,
         typename data_type3,
         typename data_type4,
         typename data_type5,
         typename data_type6,
         typename data_type7,
         typename data_type8,
         typename data_type9,
         typename data_type10> 
inline void write_debug_msg(const data_type1 &text1,
                            const data_type2 &text2,
                            const data_type3 &text3,
                            const data_type4 &text4,
                            const data_type5 &text5,
                            const data_type6 &text6,
                            const data_type7 &text7,
                            const data_type8 &text8,
                            const data_type9 &text9,
                            const data_type10 &text10)
{
    switch(config -> state_of(OUTPUT_MODE) 
           and config -> state_of(DEBUG_MODE) 
           and log_file_ready)
    {
        case true:
        #pragma omp critical
        log_file << timestamp() << "@" << text1
                                       << text2
                                       << text3
                                       << text4
                                       << text5
                                       << text6
                                       << text7
                                       << text8
                                       << text9
                                       << text10 << std::endl;
        break;
    }
};
//
//
//
template<typename data_type1,
         typename data_type2,
         typename data_type3,
         typename data_type4,
         typename data_type5,
         typename data_type6,
         typename data_type7,
         typename data_type8,
         typename data_type9,
         typename data_type10,
         typename data_type11,
         typename data_type12,
         typename data_type13,
         typename data_type14,
         typename data_type15> 
inline void write_debug_msg(const data_type1 &text1,
                            const data_type2 &text2,
                            const data_type3 &text3,
                            const data_type4 &text4,
                            const data_type5 &text5,
                            const data_type6 &text6,
                            const data_type7 &text7,
                            const data_type8 &text8,
                            const data_type9 &text9,
                            const data_type10 &text10,
                            const data_type11 &text11,
                            const data_type12 &text12,
                            const data_type13 &text13,
                            const data_type14 &text14,
                            const data_type15 &text15)
{
    switch(config -> state_of(OUTPUT_MODE) 
           and config -> state_of(DEBUG_MODE) 
           and log_file_ready)
    {
        case true:
        #pragma omp critical
        log_file << timestamp() << "@" << text1
                                       << text2
                                       << text3
                                       << text4
                                       << text5
                                       << text6
                                       << text7
                                       << text8
                                       << text9
                                       << text10
                                       << text11
                                       << text12
                                       << text13
                                       << text14
                                       << text15 << std::endl;
        break;
    }
};
//
//
//
template<typename data_type1,
         typename data_type2,
         typename data_type3,
         typename data_type4,
         typename data_type5,
         typename data_type6,
         typename data_type7,
         typename data_type8,
         typename data_type9,
         typename data_type10,
         typename data_type11,
         typename data_type12,
         typename data_type13,
         typename data_type14,
         typename data_type15,
         typename data_type16,
         typename data_type17,
         typename data_type18> 
inline void write_debug_msg(const data_type1 &text1,
                            const data_type2 &text2,
                            const data_type3 &text3,
                            const data_type4 &text4,
                            const data_type5 &text5,
                            const data_type6 &text6,
                            const data_type7 &text7,
                            const data_type8 &text8,
                            const data_type9 &text9,
                            const data_type10 &text10,
                            const data_type11 &text11,
                            const data_type12 &text12,
                            const data_type13 &text13,
                            const data_type14 &text14,
                            const data_type15 &text15,
                            const data_type16 &text16,
                            const data_type17 &text17,
                            const data_type18 &text18)
{
    switch(config -> state_of(OUTPUT_MODE) 
           and config -> state_of(DEBUG_MODE) 
           and log_file_ready)
    {
        case true:
        #pragma omp critical
        log_file << timestamp() << "@" << text1
                                       << text2
                                       << text3
                                       << text4
                                       << text5
                                       << text6
                                       << text7
                                       << text8
                                       << text9
                                       << text10
                                       << text11
                                       << text12
                                       << text13
                                       << text14
                                       << text15 
                                       << text16 
                                       << text17 
                                       << text18 << std::endl;
        break;
    }
};
