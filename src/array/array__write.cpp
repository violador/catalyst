#include "array.hpp"
//
//
//
void array::write()
{
    #pragma omp critical
    switch(config -> output_mode() 
           and true /*config -> state_of(option::logging_matrices)*/ 
           and is_2d_array)
    {
        case true:
        global_log::file << "\n- ";
        global_log::file << get_name();
        global_log::file << ":";
        global_log::file.set_new_line();
        if(size_of_column() <= 5)
        {
//
            global_log::file.set_width(MAX_PRECISION + SPACE_LENGTH + ARRAY_INDEX_LENGTH);
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
            for(unsigned int i = 1; i <= size_of_row(); ++i)
            {
                if(size_of_column() == 1)
                {
//
                    global_log::file.set_width(ARRAY_INDEX_LENGTH);
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
                    global_log::file.set_width(ARRAY_INDEX_LENGTH);
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
                    global_log::file.set_width(ARRAY_INDEX_LENGTH);
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
                    global_log::file.set_width(ARRAY_INDEX_LENGTH);
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
                    global_log::file.set_width(ARRAY_INDEX_LENGTH);
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
                for(unsigned int i = 1; i <= size_of_column()/5; ++i)
                {
//
                    global_log::file.set_width(MAX_PRECISION + SPACE_LENGTH + ARRAY_INDEX_LENGTH);
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
                    global_log::file << i + 3 + column_counter;
//
                    global_log::file.set_width(MAX_PRECISION + SPACE_LENGTH);
                    global_log::file.set_right();
                    global_log::file << i + 4 + column_counter;
//
                    global_log::file.set_new_line();
                    for(unsigned int j = 1; j <= size_of_row(); ++j)
                    {
//
                        global_log::file.set_width(ARRAY_INDEX_LENGTH);
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
                        global_log::file << get(j, i + 3 + column_counter);
//
                        global_log::file.set_scientific_notation();
                        global_log::file << get(j, i + 4 + column_counter);
//
                        global_log::file.set_new_line();
                    } // for(j)
                    column_counter += 4;
                } // for (i)
            }
            else // if(size_of_column()%5 not_eq 0)
            {
                unsigned int column_number = 0, column_counter = 0;
                for(unsigned int i = 1; i <= size_of_column()/5; ++i)
                {
//
                    global_log::file.set_width(MAX_PRECISION + SPACE_LENGTH + ARRAY_INDEX_LENGTH);
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
                    global_log::file << i + 3 + column_counter;
//
                    global_log::file.set_width(MAX_PRECISION + SPACE_LENGTH);
                    global_log::file.set_right();
                    global_log::file << i + 4 + column_counter;
//
                    global_log::file.set_new_line();
                    for(unsigned int j = 1; j <= size_of_row(); ++j)
                    {
//
                        global_log::file.set_width(ARRAY_INDEX_LENGTH);
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
                        global_log::file << get(j, i + 3 + column_counter);
//
                        global_log::file.set_scientific_notation();
                        global_log::file << get(j, i + 4 + column_counter);
//
                        global_log::file.set_new_line();
                    } // for(j)
                    column_counter += 4;
                    column_number = i + column_counter;
                } // for(i)
//
                global_log::file.set_width(MAX_PRECISION + SPACE_LENGTH + ARRAY_INDEX_LENGTH);
                global_log::file.set_right();
                global_log::file << (size_of_column()%5 >= 1? tools::convert<std::string>(column_number + 1) : "");
//
                global_log::file.set_width(MAX_PRECISION + SPACE_LENGTH);
                global_log::file.set_right();
                global_log::file << (size_of_column()%5 >= 2? tools::convert<std::string>(column_number + 2) : "");
//
                global_log::file.set_width(MAX_PRECISION + SPACE_LENGTH);
                global_log::file.set_right();
                global_log::file << (size_of_column()%5 >= 3? tools::convert<std::string>(column_number + 3) : "");
//
                global_log::file.set_width(MAX_PRECISION + SPACE_LENGTH);
                global_log::file.set_right();
                global_log::file << (size_of_column()%5 >= 4? tools::convert<std::string>(column_number + 4) : "");
//
                global_log::file.set_width(MAX_PRECISION + SPACE_LENGTH);
                global_log::file.set_right();
                global_log::file << (size_of_column()%5 >= 5? tools::convert<std::string>(column_number + 5) : "");
//
                global_log::file.set_new_line();
                unsigned int m = 0;
                for(m = 1; m <= size_of_row(); ++m)
                {
                    if(size_of_column()%5 == 1)
                    {
//
                        global_log::file.set_width(ARRAY_INDEX_LENGTH);
                        global_log::file.set_right();
                        global_log::file << m;
//
                        global_log::file.set_scientific_notation();
                        global_log::file << get(m, column_number + 1);
//
                        global_log::file.set_new_line();
                    }
                    else if(size_of_column()%5 == 2)
                    {
//
                        global_log::file.set_width(ARRAY_INDEX_LENGTH);
                        global_log::file.set_right();
                        global_log::file << m;
//
                        global_log::file.set_scientific_notation();
                        global_log::file << get(m, column_number + 1);
//
                        global_log::file.set_scientific_notation();
                        global_log::file << get(m, column_number + 2);
//
                        global_log::file.set_new_line();
                    }
                    else if(size_of_column()%5 == 3)
                    {
//
                        global_log::file.set_width(ARRAY_INDEX_LENGTH);
                        global_log::file.set_right();
                        global_log::file << m;
//
                        global_log::file.set_scientific_notation();
                        global_log::file << get(m, column_number + 1);
//
                        global_log::file.set_scientific_notation();
                        global_log::file << get(m, column_number + 2);
//
                        global_log::file.set_scientific_notation();
                        global_log::file << get(m, column_number + 3);
//
                        global_log::file.set_new_line();
                    }
                    else if(size_of_column()%5 == 4)
                    {
//
                        global_log::file.set_width(ARRAY_INDEX_LENGTH);
                        global_log::file.set_right();
                        global_log::file << m;
//
                        global_log::file.set_scientific_notation();
                        global_log::file << get(m, column_number + 1);
//
                        global_log::file.set_scientific_notation();
                        global_log::file << get(m, column_number + 2);
//
                        global_log::file.set_scientific_notation();
                        global_log::file << get(m, column_number + 3);
//
                        global_log::file.set_scientific_notation();
                        global_log::file << get(m, column_number + 4);
//
                        global_log::file.set_new_line();
                    }
                } // for(i)
            } // else if(size_of_column()%5 != 0)
        } // else if(size_of_column() > 5)  
        global_log::file.set_new_line();
        break;
    }
}
