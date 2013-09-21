/*
// References: http://www.boostpro.com/mplbook/
//
//
//
#define TEMP_MACRO(z, n, _) \ const BOOST_PP_ENUM_PARAMS_Z(z, BOOST_PP_INC(n), data_type) &text ## n \
#ifndef ARGUMENT_LIST_SIZE
    #define ARGUMENT_LIST_SIZE 10
#endif
template<BOOST_PP_ENUM_PARAMS(ARGUMENT_LIST_SIZE, typename data_type)> 
void report(BOOST_PP_REPEAT(ARGUMENT_LIST_SIZE, TEMP_MACRO, nil)) (BOOST_PP_ENUM_PARAMS(ARGUMENT_LIST_SIZE, const data_type text))
//void report(BOOST_PP_ENUM_PARAMS(ARGUMENT_LIST_SIZE, typename data_type))
            const data_type0 &text0,
            const data_type1 &text1,
            const data_type2 &text2,
            const data_type3 &text3,
            const data_type4 &text4,
            const data_type5 &text5,
            const data_type6 &text6,
            const data_type7 &text7,
            const data_type8 &text8,
            const data_type9 &text9)

//BOOST_PP_REPEAT(2, MACRO, nil)
   expands to...
   template<class T0> class X0 { };
   template<class T0, class T1> class X1 { };


{
    if(config -> state_of(OUTPUT_MODE) and log_file_ready)
    {
        if(file_manager -> exists())
        {
            LOGFILE_IS_READY:
            BOOST_PP_ENUM_PARAMS(ARGUMENT_LIST_SIZE, log_file << text);
        }
        else
        {
            init_log_file();
            goto LOGFILE_IS_READY;
        }
    }
};
#undef ARGUMENT_LIST_SIZE
*/
template<typename data_type> void report(const data_type &text)
{
    if(config -> state_of(OUTPUT_MODE) and log_file_ready)
    {
        if(file_manager -> exists())
        {
            LOGFILE_IS_READY:
            log_file << text;
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
         typename data_type2> void report(const data_type1 text1, 
                                          const data_type2 text2)
{
    if(config -> state_of(OUTPUT_MODE) and log_file_ready)
    {
        if(file_manager -> exists())
        {
            LOGFILE_IS_READY:
            log_file << text1
                     << text2;
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
         typename data_type3> void report(const data_type1 &text1, 
                                          const data_type2 &text2, 
                                          const data_type3 &text3)
{
    if(config -> state_of(OUTPUT_MODE) and log_file_ready)
    {
        if(file_manager -> exists())
        {
            LOGFILE_IS_READY:
            log_file << text1 
                     << text2 
                     << text3;
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
         typename data_type4> void report(const data_type1 &text1, 
                                          const data_type2 &text2, 
                                          const data_type3 &text3, 
                                          const data_type4 &text4)
{
    if(config -> state_of(OUTPUT_MODE) and log_file_ready)
    {
        if(file_manager -> exists())
        {
            LOGFILE_IS_READY:
            log_file << text1 
                     << text2 
                     << text3 
                     << text4;
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
         typename data_type5> void report(const data_type1 &text1, 
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
            log_file << text1
                     << text2 
                     << text3 
                     << text4 
                     << text5;
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
         typename data_type6> void report(const data_type1 &text1,
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
            log_file << text1
                     << text2 
                     << text3 
                     << text4 
                     << text5
                     << text6;
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
         typename data_type7> void report(const data_type1 &text1,
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
            log_file << text1
                     << text2
                     << text3
                     << text4
                     << text5
                     << text6
                     << text7;
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
         typename data_type8> void report(const data_type1 &text1,
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
            log_file << text1
                     << text2
                     << text3
                     << text4
                     << text5
                     << text6
                     << text7
                     << text8;
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
         typename data_type9> void report(const data_type1 &text1,
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
            log_file << text1
                     << text2
                     << text3
                     << text4
                     << text5
                     << text6
                     << text7
                     << text8
                     << text9;
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
         typename data_type10> void report(const data_type1 &text1,
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
            log_file << text1
                     << text2
                     << text3
                     << text4
                     << text5
                     << text6
                     << text7
                     << text8
                     << text9
                     << text10;
        }
        else
        {
            init_log_file();
            goto LOGFILE_IS_READY;
        }
    }
};
