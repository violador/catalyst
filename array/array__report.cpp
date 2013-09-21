#include "array.hpp"
//
//
//
void array::report()
{
    if(config -> state_of(OUTPUT_MODE) and is_2d_array)
    {
        if(log_file_manager.file_system::is_open())
        {
            LOGFILE_IS_READY:
            log_file << "\n- " << get_name() << ":" << std::endl;
            if(size_of_column() <= 5)
            {
//
                log_file.width(config -> numeric_precision() + 8);
                log_file.fill(' ');
                log_file << std::right << (size_of_column() >= 1? "1" : "");
//
                log_file.width(config -> numeric_precision() + 3);
                log_file.fill(' ');
                log_file << std::right << (size_of_column() >= 2? "2" : "");
//
                log_file.width(config -> numeric_precision() + 3);
                log_file.fill(' ');
                log_file << std::right << (size_of_column() >= 3? "3" : "");
//
                log_file.width(config -> numeric_precision() + 3);
                log_file.fill(' ');
                log_file << std::right << (size_of_column() >= 4? "4" : "");
//
                log_file.width(config -> numeric_precision() + 3);
                log_file.fill(' ');
                log_file << std::right << (size_of_column() >= 5? "5" : "") << std::endl;
//
                for(unsigned int i = 1; i <= size_of_row(); i++)
                {
                    if(size_of_column() == 1)
                    {
//
                        log_file.width(5);
                        log_file.fill(' ');
                        log_file << std::right << i;
//
                        log_file.width(config -> numeric_precision() + 3);
                        log_file.fill(' ');
                        log_file << std::right << get(i, 1) << std::endl;
//
                    }
                    else if(size_of_column() == 2)
                    {
//
                        log_file.width(5);
                        log_file.fill(' ');
                        log_file << std::right << i;
//
                        log_file.width(config -> numeric_precision() + 3);
                        log_file.fill(' ');
                        log_file << std::right << get(i, 1);
//
                        log_file.width(config -> numeric_precision() + 3);
                        log_file.fill(' ');
                        log_file << std::right << get(i, 2) << std::endl;
//
                    }
                    else if(size_of_column() == 3)
                    {
//
                        log_file.width(5);
                        log_file.fill(' ');
                        log_file << std::right << i;
//
                        log_file.width(config -> numeric_precision() + 3);
                        log_file.fill(' ');
                        log_file << std::right << get(i, 1);
//
                        log_file.width(config -> numeric_precision() + 3);
                        log_file.fill(' ');
                        log_file << std::right << get(i, 2);
//
                        log_file.width(config -> numeric_precision() + 3);
                        log_file.fill(' ');
                        log_file << std::right << get(i, 3) << std::endl;
//
                    }
                    else if(size_of_column() == 4)
                    {
//
                        log_file.width(5);
                        log_file.fill(' ');
                        log_file << std::right << i;
//
                        log_file.width(config -> numeric_precision() + 3);
                        log_file.fill(' ');
                        log_file << std::right << get(i, 1);
//
                        log_file.width(config -> numeric_precision() + 3);
                        log_file.fill(' ');
                        log_file << std::right << get(i, 2);
//
                        log_file.width(config -> numeric_precision() + 3);
                        log_file.fill(' ');
                        log_file << std::right << get(i, 3);
//
                        log_file.width(config -> numeric_precision() + 3);
                        log_file.fill(' ');
                        log_file << std::right << get(i, 4) << std::endl;
//
                    }
                    else if(size_of_column() == 5)
                    {
//
                        log_file.width(5);
                        log_file.fill(' ');
                        log_file << std::right << i;
//
                        log_file.width(config -> numeric_precision() + 3);
                        log_file.fill(' ');
                        log_file << std::right << get(i, 1);
//
                        log_file.width(config -> numeric_precision() + 3);
                        log_file.fill(' ');
                        log_file << std::right << get(i, 2);
//
                        log_file.width(config -> numeric_precision() + 3);
                        log_file.fill(' ');
                        log_file << std::right << get(i, 3);
//
                        log_file.width(config -> numeric_precision() + 3);
                        log_file.fill(' ');
                        log_file << std::right << get(i, 4);
//
                        log_file.width(config -> numeric_precision() + 3);
                        log_file.fill(' ');
                        log_file << std::right << get(i, 5) << std::endl;
//
                    }
                }
            }
            else // if(size_of_column() > 5)
            {
                if(size_of_column()%5 == 0)
                {
                    unsigned int column_counter = 0;
                    for(unsigned int i = 1; i <= size_of_column()/5; i++)
                    {
//
                        log_file.width(config -> numeric_precision() + 8);
                        log_file.fill(' ');
                        log_file << std::right << i + column_counter;
//
                        log_file.width(config -> numeric_precision() + 3);
                        log_file.fill(' ');
                        log_file << std::right << i + 1 + column_counter;
//
                        log_file.width(config -> numeric_precision() + 3);
                        log_file.fill(' ');
                        log_file << std::right << i + 2 + column_counter;
//
                        log_file.width(config -> numeric_precision() + 3);
                        log_file.fill(' ');
                        log_file << std::right << i + 3 + column_counter;
//
                        log_file.width(config -> numeric_precision() + 3);
                        log_file.fill(' ');
                        log_file << std::right << i + 4 + column_counter << std::endl;
//
                        for(unsigned int j = 1; j <= size_of_row(); j++)
                        {
//
                            log_file.width(5);
                            log_file.fill(' ');
                            log_file << std::right << j;
//
                            log_file.width(config -> numeric_precision() + 3);
                            log_file.fill(' ');
                            log_file << std::right << get(j, i + column_counter);
//
                            log_file.width(config -> numeric_precision() + 3);
                            log_file.fill(' ');
                            log_file << std::right << get(j, i + 1 + column_counter);
//
                            log_file.width(config -> numeric_precision() + 3);
                            log_file.fill(' ');
                            log_file << std::right << get(j, i + 2 + column_counter);
//
                            log_file.width(config -> numeric_precision() + 3);
                            log_file.fill(' ');
                            log_file << std::right << get(j, i + 3 + column_counter);
//
                            log_file.width(config -> numeric_precision() + 3);
                            log_file.fill(' ');
                            log_file << std::right << get(j, i + 4 + column_counter) << std::endl;
//
                        } // for(j)
                        column_counter += 4;
                    } // for (i)
                }
                else // if(size_of_column()%5 != 0)
                {
                }
            }  
        }
        else // if(not log_file_manager.file_system::is_open())
        {
            log_file_manager.file_system::init(config -> filename_of(LOG_FILE), config -> dir_path_of(SCRATCH));
            log_file_manager.file_system::open_txt_output(log_file);
            if(log_file_manager.file_system::is_open())
            {
                goto LOGFILE_IS_READY;
            }
        }
    }
}
