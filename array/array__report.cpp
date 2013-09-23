#include "array.hpp"
//
//
//
void array::report()
{
    if(setup_ready and config -> state_of(OUTPUT_MODE) and is_2d_array)
    {
        if(log_file -> exists())
        {
            LOGFILE_IS_READY:
            log_file -> output << "\n- " << get_name() << ":" << std::endl;
            if(size_of_column() <= 5)
            {
//
                log_file -> output.width(MAX_PRECISION + 8);
                log_file -> output.fill(' ');
                log_file -> output << std::right << (size_of_column() >= 1? "1" : "");
//
                log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
                log_file -> output.fill(' ');
                log_file -> output << std::right << (size_of_column() >= 2? "2" : "");
//
                log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
                log_file -> output.fill(' ');
                log_file -> output << std::right << (size_of_column() >= 3? "3" : "");
//
                log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
                log_file -> output.fill(' ');
                log_file -> output << std::right << (size_of_column() >= 4? "4" : "");
//
                log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
                log_file -> output.fill(' ');
                log_file -> output << std::right << (size_of_column() >= 5? "5" : "");
//
                log_file -> output << std::endl;
                for(unsigned int i = 1; i <= size_of_row(); i++)
                {
                    if(size_of_column() == 1)
                    {
//
                        log_file -> output.width(5);
                        log_file -> output.fill(' ');
                        log_file -> output << std::right << i;
//
                        log_file -> output << std::scientific;
                        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
                        log_file -> output.fill(' ');
                        log_file -> output.precision(config -> numeric_precision());
                        log_file -> output << std::right << get(i, 1) << std::endl;
//
                    }
                    else if(size_of_column() == 2)
                    {
//
                        log_file -> output.width(5);
                        log_file -> output.fill(' ');
                        log_file -> output << std::right << i;
//
                        log_file -> output << std::scientific;
                        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
                        log_file -> output.precision(config -> numeric_precision());
                        log_file -> output << std::right << get(i, 1);
//
                        log_file -> output << std::scientific;
                        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
                        log_file -> output.precision(config -> numeric_precision());
                        log_file -> output << std::right << get(i, 2) << std::endl;
//
                    }
                    else if(size_of_column() == 3)
                    {
//
                        log_file -> output.width(5);
                        log_file -> output.fill(' ');
                        log_file -> output << std::right << i;
//
                        log_file -> output << std::scientific;
                        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
                        log_file -> output.precision(config -> numeric_precision());
                        log_file -> output << std::right << get(i, 1);
//
                        log_file -> output << std::scientific;
                        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
                        log_file -> output.precision(config -> numeric_precision());
                        log_file -> output << std::right << get(i, 2);
//
                        log_file -> output << std::scientific;
                        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
                        log_file -> output.precision(config -> numeric_precision());
                        log_file -> output << std::right << get(i, SPACE_LENGTH) << std::endl;
//
                    }
                    else if(size_of_column() == 4)
                    {
//
                        log_file -> output.width(5);
                        log_file -> output.fill(' ');
                        log_file -> output << std::right << i;
//
                        log_file -> output << std::scientific;
                        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
                        log_file -> output.precision(config -> numeric_precision());
                        log_file -> output << std::right << get(i, 1);
//
                        log_file -> output << std::scientific;
                        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
                        log_file -> output.precision(config -> numeric_precision());
                        log_file -> output << std::right << get(i, 2);
//
                        log_file -> output << std::scientific;
                        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
                        log_file -> output.precision(config -> numeric_precision());
                        log_file -> output << std::right << get(i, SPACE_LENGTH);
//
                        log_file -> output << std::scientific;
                        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
                        log_file -> output.precision(config -> numeric_precision());
                        log_file -> output << std::right << get(i, 4) << std::endl;
//
                    }
                    else if(size_of_column() == 5)
                    {
//
                        log_file -> output.width(5);
                        log_file -> output.fill(' ');
                        log_file -> output << std::right << i;
//
                        log_file -> output << std::scientific;
                        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
                        log_file -> output.precision(config -> numeric_precision());
                        log_file -> output << std::right << get(i, 1);
//
                        log_file -> output << std::scientific;
                        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
                        log_file -> output.precision(config -> numeric_precision());
                        log_file -> output << std::right << get(i, 2);
//
                        log_file -> output << std::scientific;
                        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
                        log_file -> output.precision(config -> numeric_precision());
                        log_file -> output << std::right << get(i, SPACE_LENGTH);
//
                        log_file -> output << std::scientific;
                        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
                        log_file -> output.precision(config -> numeric_precision());
                        log_file -> output << std::right << get(i, 4);
//
                        log_file -> output << std::scientific;
                        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
                        log_file -> output.precision(config -> numeric_precision());
                        log_file -> output << std::right << get(i, 5) << std::endl;
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
                        log_file -> output.width(MAX_PRECISION + 8);
                        log_file -> output.fill(' ');
                        log_file -> output << std::right << i + column_counter;
//
                        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
                        log_file -> output.fill(' ');
                        log_file -> output << std::right << i + 1 + column_counter;
//
                        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
                        log_file -> output.fill(' ');
                        log_file -> output << std::right << i + 2 + column_counter;
//
                        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
                        log_file -> output.fill(' ');
                        log_file -> output << std::right << i + SPACE_LENGTH + column_counter;
//
                        log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
                        log_file -> output.fill(' ');
                        log_file -> output << std::right << i + 4 + column_counter << std::endl;
//
                        for(unsigned int j = 1; j <= size_of_row(); j++)
                        {
//
                            log_file -> output.width(5);
                            log_file -> output << std::right << j;
//
                            log_file -> output << std::scientific;
                            log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
                            log_file -> output.precision(config -> numeric_precision());
                            log_file -> output << std::right << get(j, i + column_counter);
//
                            log_file -> output << std::scientific;
                            log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
                            log_file -> output.precision(config -> numeric_precision());
                            log_file -> output << std::right << get(j, i + 1 + column_counter);
//
                            log_file -> output << std::scientific;
                            log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
                            log_file -> output.precision(config -> numeric_precision());
                            log_file -> output << std::right << get(j, i + 2 + column_counter);
//
                            log_file -> output << std::scientific;
                            log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
                            log_file -> output.precision(config -> numeric_precision());
                            log_file -> output << std::right << get(j, i + SPACE_LENGTH + column_counter);
//
                            log_file -> output << std::scientific;
                            log_file -> output.width(MAX_PRECISION + SPACE_LENGTH);
                            log_file -> output.precision(config -> numeric_precision());
                            log_file -> output << std::right << get(j, i + 4 + column_counter) << std::endl;
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
        else // if(not log_file -> exists())
        {
            log_file -> init_log_file();
            if(log_file -> exists())
            {
                goto LOGFILE_IS_READY;
            }
        }
    }
}
