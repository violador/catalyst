#include "array.hpp"
//
//
//
void array::report()
{
    if(setup_ready and config -> state_of(OUTPUT_MODE) and is_2d_array)
    {
        if(global_log::file.exists())
        {
            LOGFILE_IS_READY:
            global_log::file << "\n- ";
            global_log::file << get_name();
            global_log::file << ":";
            global_log::file.set_new_line();
            if(size_of_column() <= 5)
            {
//
                global_log::file.set_width(MAX_PRECISION + 8);
                global_log::file.set_right();
                global_log::file << (size_of_column() >= 1? "1" : "");
//
                global_log::file.set_width(MAX_PRECISION + SPACE_LENGTH);
                global_log::file.set_right();
                global_log::file << (size_of_column() >= 2? "2" : "");
//
                global_log::file.set_width(MAX_PRECISION + SPACE_LENGTH);
                global_log::file.set_right();
                global_log::file << (size_of_column() >= 3? "3" : "");
//
                global_log::file.set_width(MAX_PRECISION + SPACE_LENGTH);
                global_log::file.set_right();
                global_log::file << (size_of_column() >= 4? "4" : "");
//
                global_log::file.set_width(MAX_PRECISION + SPACE_LENGTH);
                global_log::file.set_right();
                global_log::file << (size_of_column() >= 5? "5" : "");
//
                global_log::file.set_new_line();
                for(unsigned int i = 1; i <= size_of_row(); i++)
                {
                    if(size_of_column() == 1)
                    {
//
                        global_log::file.set_width(5);
                        global_log::file.set_right();
                        global_log::file << i;
//
                        global_log::file.set_scientific_notation();
                        global_log::file << get(i, 1);
//
                        global_log::file.set_new_line();
                    }
                    else if(size_of_column() == 2)
                    {
//
                        global_log::file.set_width(5);
                        global_log::file.set_right();
                        global_log::file << i;
//
                        global_log::file.set_scientific_notation();
                        global_log::file << get(i, 1);
//
                        global_log::file.set_scientific_notation();
                        global_log::file << get(i, 2);
//
                        global_log::file.set_new_line();
                    }
                    else if(size_of_column() == 3)
                    {
//
                        global_log::file.set_width(5);
                        global_log::file.set_right();
                        global_log::file << i;
//
                        global_log::file.set_scientific_notation();
                        global_log::file << get(i, 1);
//
                        global_log::file.set_scientific_notation();
                        global_log::file << get(i, 2);
//
                        global_log::file.set_scientific_notation();
                        global_log::file << get(i, 3);
//
                        global_log::file.set_new_line();
                    }
                    else if(size_of_column() == 4)
                    {
//
                        global_log::file.set_width(5);
                        global_log::file.set_right();
                        global_log::file << i;
//
                        global_log::file.set_scientific_notation();
                        global_log::file << get(i, 1);
//
                        global_log::file.set_scientific_notation();
                        global_log::file << get(i, 2);
//
                        global_log::file.set_scientific_notation();
                        global_log::file << get(i, 3);
//
                        global_log::file.set_scientific_notation();
                        global_log::file << get(i, 4);
//
                        global_log::file.set_new_line();
                    }
                    else if(size_of_column() == 5)
                    {
//
                        global_log::file.set_width(5);
                        global_log::file.set_right();
                        global_log::file << i;
//
                        global_log::file.set_scientific_notation();
                        global_log::file << get(i, 1);
//
                        global_log::file.set_scientific_notation();
                        global_log::file << get(i, 2);
//
                        global_log::file.set_scientific_notation();
                        global_log::file << get(i, 3);
//
                        global_log::file.set_scientific_notation();
                        global_log::file << get(i, 4);
//
                        global_log::file.set_scientific_notation();
                        global_log::file << get(i, 5);
//
                        global_log::file.set_new_line();
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
                        global_log::file.set_width(MAX_PRECISION + 8);
                        global_log::file.set_right();
                        global_log::file << i + column_counter;
//
                        global_log::file.set_width(MAX_PRECISION + SPACE_LENGTH);
                        global_log::file.set_right();
                        global_log::file << i + 1 + column_counter;
//
                        global_log::file.set_width(MAX_PRECISION + SPACE_LENGTH);
                        global_log::file.set_right();
                        global_log::file << i + 2 + column_counter;
//
                        global_log::file.set_width(MAX_PRECISION + SPACE_LENGTH);
                        global_log::file.set_right();
                        global_log::file << i + SPACE_LENGTH + column_counter;
//
                        global_log::file.set_width(MAX_PRECISION + SPACE_LENGTH);
                        global_log::file.set_right();
                        global_log::file << i + 4 + column_counter;
//
                        global_log::file.set_new_line();
                        for(unsigned int j = 1; j <= size_of_row(); j++)
                        {
//
                            global_log::file.set_width(5);
                            global_log::file << j;
//
                            global_log::file.set_scientific_notation();
                            global_log::file << get(j, i + column_counter);
//
                            global_log::file.set_scientific_notation();
                            global_log::file << get(j, i + 1 + column_counter);
//
                            global_log::file.set_scientific_notation();
                            global_log::file << get(j, i + 2 + column_counter);
//
                            global_log::file.set_scientific_notation();
                            global_log::file << get(j, i + SPACE_LENGTH + column_counter);
//
                            global_log::file.set_scientific_notation();
                            global_log::file << get(j, i + 4 + column_counter);
//
                            global_log::file.set_new_line();
                        } // for(j)
                        column_counter += 4;
                    } // for (i)
                }
                else // if(size_of_column()%5 != 0)
                {
                }
            }  
        }
        else // if(not global_log::file -> exists())
        {
            global_log::file.init_log_file();
            if(global_log::file.exists())
            {
                goto LOGFILE_IS_READY;
            }
        }
    }
}
