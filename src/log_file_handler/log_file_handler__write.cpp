//
//
//
template<typename data_type1> 
void write(const data_type1 &text1)
{
    if(config -> state_of(OUTPUT_MODE) and log_file_ready)
    {
        if(file_manager -> exists())
        {
            LOGFILE_IS_READY:
            log_file << timestamp() << text1 << std::endl;
        }
        else
        {
            init_log_file();
            goto LOGFILE_IS_READY;
        }
    }
};
//
//
//
template<typename data_type1, typename data_type2> 
void write(const data_type1 text1, const data_type2 text2)
{
    if(config -> state_of(OUTPUT_MODE) and log_file_ready)
    {
        if(file_manager -> exists())
        {
            LOGFILE_IS_READY:
            log_file << timestamp() << text1
                                    << text2 << std::endl;
        }
        else
        {
            init_log_file();
            goto LOGFILE_IS_READY;
        }
    }
};
//
//
//
template<typename data_type1, typename data_type2, typename data_type3>
void write(const data_type1 &text1, const data_type2 &text2, const data_type3 &text3)
{
    if(config -> state_of(OUTPUT_MODE) and log_file_ready)
    {
        if(file_manager -> exists())
        {
            LOGFILE_IS_READY:
            log_file << timestamp() << text1 
                                    << text2 
                                    << text3 << std::endl;
        }
        else
        {
            init_log_file();
            goto LOGFILE_IS_READY;
        }
    }
};
//
//
//
template<typename data_type1, 
         typename data_type2, 
         typename data_type3, 
         typename data_type4> 
void write(const data_type1 &text1, 
           const data_type2 &text2, 
           const data_type3 &text3, 
           const data_type4 &text4)
{
    if(config -> state_of(OUTPUT_MODE) and log_file_ready)
    {
        if(file_manager -> exists())
        {
            LOGFILE_IS_READY:
            log_file << timestamp() << text1 
                                    << text2 
                                    << text3 
                                    << text4 << std::endl;
        }
        else
        {
            init_log_file();
            goto LOGFILE_IS_READY;
        }
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
void write(const data_type1 &text1, 
           const data_type2 &text2,
           const data_type3 &text3, 
           const data_type4 &text4,
           const data_type5 &text5)
{
    if(config -> state_of(OUTPUT_MODE) and log_file_ready)
    {
        if(file_manager -> exists())
        {
            LOGFILE_IS_READY:
            log_file << timestamp() << text1
                                    << text2 
                                    << text3 
                                    << text4 
                                    << text5 << std::endl;
        }
        else
        {
            init_log_file();
            goto LOGFILE_IS_READY;
        }
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
void write(const data_type1 &text1,
           const data_type2 &text2,
           const data_type3 &text3,
           const data_type4 &text4,
           const data_type5 &text5,
           const data_type6 &text6)
{
    if(config -> state_of(OUTPUT_MODE) and log_file_ready)
    {
        if(file_manager -> exists())
        {
            LOGFILE_IS_READY:
            log_file << timestamp() << text1
                                    << text2 
                                    << text3 
                                    << text4 
                                    << text5
                                    << text6 << std::endl;
        }
        else
        {
            init_log_file();
            goto LOGFILE_IS_READY;
        }
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
void write(const data_type1 &text1,
           const data_type2 &text2,
           const data_type3 &text3,
           const data_type4 &text4,
           const data_type5 &text5,
           const data_type6 &text6,
           const data_type7 &text7)
{
    if(config -> state_of(OUTPUT_MODE) and log_file_ready)
    {
        if(file_manager -> exists())
        {
            LOGFILE_IS_READY:
            log_file << timestamp() << text1
                                    << text2
                                    << text3
                                    << text4
                                    << text5
                                    << text6
                                    << text7 << std::endl;
        }
        else
        {
            init_log_file();
            goto LOGFILE_IS_READY;
        }
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
void write(const data_type1 &text1,
           const data_type2 &text2,
           const data_type3 &text3,
           const data_type4 &text4,
           const data_type5 &text5,
           const data_type6 &text6,
           const data_type7 &text7,
           const data_type8 &text8)
{
    if(config -> state_of(OUTPUT_MODE) and log_file_ready)
    {
        if(file_manager -> exists())
        {
            LOGFILE_IS_READY:
            log_file << timestamp() << text1
                                    << text2
                                    << text3
                                    << text4
                                    << text5
                                    << text6
                                    << text7
                                    << text8 << std::endl;
        }
        else
        {
            init_log_file();
            goto LOGFILE_IS_READY;
        }
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
void write(const data_type1 &text1,
           const data_type2 &text2,
           const data_type3 &text3,
           const data_type4 &text4,
           const data_type5 &text5,
           const data_type6 &text6,
           const data_type7 &text7,
           const data_type8 &text8,
           const data_type9 &text9)
{
    if(config -> state_of(OUTPUT_MODE) and log_file_ready)
    {
        if(file_manager -> exists())
        {
            LOGFILE_IS_READY:
            log_file << timestamp() << text1
                                    << text2
                                    << text3
                                    << text4
                                    << text5
                                    << text6
                                    << text7
                                    << text8
                                    << text9 << std::endl;
        }
        else
        {
            init_log_file();
            goto LOGFILE_IS_READY;
        }
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
void write(const data_type1 &text1,
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
    if(config -> state_of(OUTPUT_MODE) and log_file_ready)
    {
        if(file_manager -> exists())
        {
            LOGFILE_IS_READY:
            log_file << timestamp() << text1
                                    << text2
                                    << text3
                                    << text4
                                    << text5
                                    << text6
                                    << text7
                                    << text8
                                    << text9
                                    << text10 << std::endl;
        }
        else
        {
            init_log_file();
            goto LOGFILE_IS_READY;
        }
    }
};
