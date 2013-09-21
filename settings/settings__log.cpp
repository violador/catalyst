//
//
//
template<typename data_type> void log(const data_type &text)
{
    if(output_mode_on)
    {
        if(logfile_ready)
        {
            LOGFILE_IS_READY:
            std::ofstream log_file(log_filename.c_str(), std::ios::app);
            if(log_file.is_open() && log_file.good())
            {
                log_file << text;
                log_file.close();
            }
        }
        else
        {
            init_log();
            goto LOGFILE_IS_READY;
        }
    }
};
//
//
//
template<typename data_type1, 
         typename data_type2> void log(const data_type1 text1, 
                                       const data_type2 text2)
{
    if(output_mode_on)
    {
        if(logfile_ready)
        {
            LOGFILE_IS_READY:
            std::ofstream log_file(log_filename.c_str(), std::ios::app);
            if(log_file.is_open() && log_file.good())
            {
                log_file << text1
                         << text2;
                log_file.close();
            }
        }
        else
        {
            init_log();
            goto LOGFILE_IS_READY;
        }
    }
};
//
//
//
template<typename data_type1, 
         typename data_type2, 
         typename data_type3> void log(const data_type1 &text1, 
                                       const data_type2 &text2, 
                                       const data_type3 &text3)
{
    if(output_mode_on)
    {
        if(logfile_ready)
        {
            LOGFILE_IS_READY:
            std::ofstream log_file(log_filename.c_str(), std::ios::app);
            if(log_file.is_open() && log_file.good())
            {
                log_file << text1 
                         << text2 
                         << text3;
                log_file.close();
            }
        }
        else
        {
            init_log();
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
         typename data_type4> void log(const data_type1 &text1, 
                                       const data_type2 &text2, 
                                       const data_type3 &text3, 
                                       const data_type4 &text4)
{
    if(output_mode_on)
    {
        if(logfile_ready)
        {
            LOGFILE_IS_READY:
            std::ofstream log_file(log_filename.c_str(), std::ios::app);
            if(log_file.is_open() && log_file.good())
            {
                log_file << text1 
                         << text2 
                         << text3 
                         << text4;
                log_file.close();
            }
        }
        else
        {
            init_log();
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
         typename data_type5> void log(const data_type1 &text1, 
                                       const data_type2 &text2,
                                       const data_type3 &text3, 
                                       const data_type4 &text4,
                                       const data_type5 &text5)
{
    if(output_mode_on)
    {
        if(logfile_ready)
        {
            LOGFILE_IS_READY:
            std::ofstream log_file(log_filename.c_str(), std::ios::app);
            if(log_file.is_open() && log_file.good())
            {
                log_file << text1
                         << text2 
                         << text3 
                         << text4 
                         << text5;
                log_file.close();
            }
        }
        else
        {
            init_log();
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
         typename data_type6> void log(const data_type1 &text1,
                                       const data_type2 &text2,
                                       const data_type3 &text3,
                                       const data_type4 &text4,
                                       const data_type5 &text5,
                                       const data_type6 &text6)
{
    if(output_mode_on)
    {
        if(logfile_ready)
        {
            LOGFILE_IS_READY:
            std::ofstream log_file(log_filename.c_str(), std::ios::app);
            if(log_file.is_open() && log_file.good())
            {
                log_file << text1
                         << text2 
                         << text3 
                         << text4 
                         << text5
                         << text6;
                log_file.close();
            }
        }
        else
        {
            init_log();
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
         typename data_type7> void log(const data_type1 &text1,
                                       const data_type2 &text2,
                                       const data_type3 &text3,
                                       const data_type4 &text4,
                                       const data_type5 &text5,
                                       const data_type6 &text6,
                                       const data_type7 &text7)
{
    if(output_mode_on)
    {
        if(logfile_ready)
        {
            LOGFILE_IS_READY:
            std::ofstream log_file(log_filename.c_str(), std::ios::app);
            if(log_file.is_open() && log_file.good())
            {
                log_file << text1
                         << text2
                         << text3
                         << text4
                         << text5
                         << text6
                         << text7;
                log_file.close();
            }
        }
        else
        {
            init_log();
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
         typename data_type8> void log(const data_type1 &text1,
                                       const data_type2 &text2,
                                       const data_type3 &text3,
                                       const data_type4 &text4,
                                       const data_type5 &text5,
                                       const data_type6 &text6,
                                       const data_type7 &text7,
                                       const data_type8 &text8)
{
    if(output_mode_on)
    {
        if(logfile_ready)
        {
            LOGFILE_IS_READY:
            std::ofstream log_file(log_filename.c_str(), std::ios::app);
            if(log_file.is_open() && log_file.good())
            {
                log_file << text1
                         << text2
                         << text3
                         << text4
                         << text5
                         << text6
                         << text7
                         << text8;
                log_file.close();
            }
        }
        else
        {
            init_log();
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
         typename data_type9> void log(const data_type1 &text1,
                                       const data_type2 &text2,
                                       const data_type3 &text3,
                                       const data_type4 &text4,
                                       const data_type5 &text5,
                                       const data_type6 &text6,
                                       const data_type7 &text7,
                                       const data_type8 &text8,
                                       const data_type9 &text9)
{
    if(output_mode_on)
    {
        if(logfile_ready)
        {
            LOGFILE_IS_READY:
            std::ofstream log_file(log_filename.c_str(), std::ios::app);
            if(log_file.is_open() && log_file.good())
            {
                log_file << text1
                         << text2
                         << text3
                         << text4
                         << text5
                         << text6
                         << text7
                         << text8
                         << text9;
                log_file.close();
            }
        }
        else
        {
            init_log();
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
         typename data_type10> void log(const data_type1 &text1,
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
    if(output_mode_on)
    {
        if(logfile_ready)
        {
            LOGFILE_IS_READY:
            std::ofstream log_file(log_filename.c_str(), std::ios::app);
            if(log_file.is_open() && log_file.good())
            {
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
                log_file.close();
            }
        }
        else
        {
            init_log();
            goto LOGFILE_IS_READY;
        }
    }
};
//
//
//

//void log(array &array_to_write)
//{};
/*
{
    if(output_mode_on)
    {
        if(logfile_ready)
        {
            LOGFILE_IS_READY:
            std::ofstream log_file(log_filename.c_str(), std::ios::out | std::ios::app);
            if(log_file.is_open() && log_file.good())
            {
                log_file << "\n- " << array_to_write.get_name() << ":" << std::endl;
                if(array_to_write.size_of_column() <= 5)
                {
//
                    log_file.width(num_precision + 8);
                    log_file.fill(' ');
                    log_file << std::right << (array_to_write.size_of_column() >= 1? "1": "");
//
                    log_file.width(num_precision + 3);
                    log_file.fill(' ');
                    log_file << std::right << (array_to_write.size_of_column() >= 2? "2": "");
//
                    log_file.width(num_precision + 3);
                    log_file.fill(' ');
                    log_file << std::right << (array_to_write.size_of_column() >= 3? "3": "");
//
                    log_file.width(num_precision + 3);
                    log_file.fill(' ');
                    log_file << std::right << (array_to_write.size_of_column() >= 4? "4": "");
//
                    log_file.width(num_precision + 3);
                    log_file.fill(' ');
                    log_file << std::right << (array_to_write.size_of_column() >= 5? "5": "") << std::endl;
//
                    for(unsigned int i = 1; i <= array_to_write.size_of_row(); i++)
                    {
                        if(array_to_write.size_of_column() == 1)
                        {
//
                            log_file.width(5);
                            log_file.fill(' ');
                            log_file << std::right << i;
//
                            log_file.width(num_precision + 3);
                            log_file.fill(' ');
                            log_file << std::right << array_to_write.get(i, 1) << std::endl;
//
                        }
                        else if(array_to_write.size_of_column() == 2)
                        {
//
                            log_file.width(5);
                            log_file.fill(' ');
                            log_file << std::right << i;
//
                            log_file.width(num_precision + 3);
                            log_file.fill(' ');
                            log_file << std::right << array_to_write.get(i, 1);
//
                            log_file.width(num_precision + 3);
                            log_file.fill(' ');
                            log_file << std::right << array_to_write.get(i, 2) << std::endl;
//
                        }
                        else if(array_to_write.size_of_column() == 3)
                        {
//
                            log_file.width(5);
                            log_file.fill(' ');
                            log_file << std::right << i;
//
                            log_file.width(num_precision + 3);
                            log_file.fill(' ');
                            log_file << std::right << array_to_write.get(i, 1);
//
                            log_file.width(num_precision + 3);
                            log_file.fill(' ');
                            log_file << std::right << array_to_write.get(i, 2);
//
                            log_file.width(num_precision + 3);
                            log_file.fill(' ');
                            log_file << std::right << array_to_write.get(i, 3) << std::endl;
//
                        }
                        else if(array_to_write.size_of_column() == 4)
                        {
//
                            log_file.width(5);
                            log_file.fill(' ');
                            log_file << std::right << i;
//
                            log_file.width(num_precision + 3);
                            log_file.fill(' ');
                            log_file << std::right << array_to_write.get(i, 1);
//
                            log_file.width(num_precision + 3);
                            log_file.fill(' ');
                            log_file << std::right << array_to_write.get(i, 2);
//
                            log_file.width(num_precision + 3);
                            log_file.fill(' ');
                            log_file << std::right << array_to_write.get(i, 3);
//
                            log_file.width(num_precision + 3);
                            log_file.fill(' ');
                            log_file << std::right << array_to_write.get(i, 4) << std::endl;
//
                        }
                        else if(array_to_write.size_of_column() == 5)
                        {
//
                            log_file.width(5);
                            log_file.fill(' ');
                            log_file << std::right << i;
//
                            log_file.width(num_precision + 3);
                            log_file.fill(' ');
                            log_file << std::right << array_to_write.get(i, 1);
//
                            log_file.width(num_precision + 3);
                            log_file.fill(' ');
                            log_file << std::right << array_to_write.get(i, 2);
//
                            log_file.width(num_precision + 3);
                            log_file.fill(' ');
                            log_file << std::right << array_to_write.get(i, 3);
//
                            log_file.width(num_precision + 3);
                            log_file.fill(' ');
                            log_file << std::right << array_to_write.get(i, 4);
//
                            log_file.width(num_precision + 3);
                            log_file.fill(' ');
                            log_file << std::right << array_to_write.get(i, 5) << std::endl;
//
                        }
                    }
                }
                else // if(array_to_write.size_of_column() > 5)
                {
                    if(array_to_write.size_of_column()%5 == 0)
                    {
                        unsigned int column_counter = 0;
                        for(unsigned int i = 1; i <= array_to_write.size_of_column()/5; i++)
                        {
//
                            log_file.width(num_precision + 8);
                            log_file.fill(' ');
                            log_file << std::right << i + column_counter;
//
                            log_file.width(num_precision + 3);
                            log_file.fill(' ');
                            log_file << std::right << i + 1 + column_counter;
//
                            log_file.width(num_precision + 3);
                            log_file.fill(' ');
                            log_file << std::right << i + 2 + column_counter;
//
                            log_file.width(num_precision + 3);
                            log_file.fill(' ');
                            log_file << std::right << i + 3 + column_counter;
//
                            log_file.width(num_precision + 3);
                            log_file.fill(' ');
                            log_file << std::right << i + 4 + column_counter << std::endl;
//
                            for(unsigned int j = 1; j <= array_to_write.size_of_row(); j++)
                            {
//
                                log_file.width(5);
                                log_file.fill(' ');
                                log_file << std::right << j;
//
                                log_file.width(num_precision + 3);
                                log_file.fill(' ');
                                log_file << std::right << array_to_write.get(j, i + column_counter);
//
                                log_file.width(num_precision + 3);
                                log_file.fill(' ');
                                log_file << std::right << array_to_write.get(j, i + 1 + column_counter);
//
                                log_file.width(num_precision + 3);
                                log_file.fill(' ');
                                log_file << std::right << array_to_write.get(j, i + 2 + column_counter);
//
                                log_file.width(num_precision + 3);
                                log_file.fill(' ');
                                log_file << std::right << array_to_write.get(j, i + 3 + column_counter);
//
                                log_file.width(num_precision + 3);
                                log_file.fill(' ');
                                log_file << std::right << array_to_write.get(j, i + 4 + column_counter) << std::endl;
//
                            } // for(j)
                            column_counter += 4;
                        } // for (i)
                    }
                    else // if(array_to_write.size_of_column()%5 != 0)
                    {
                    }
                }  
            }
            else // if(!log_file.is_open() || !log_file.good())
            {
//
            }
        }
        else // if(!logfile_ready)
        {
            init_log();
            goto LOGFILE_IS_READY;
        }
    }
};
*/
