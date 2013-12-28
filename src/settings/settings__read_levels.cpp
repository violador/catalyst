#include "settings.hpp"
//
//
//
void settings::read_levels()
{
    switch(total_tasks >= 1)
    {   
        case false:
        {   
            theory_level = new unsigned int[1];
            theory_level[0] = 2;
        }
        break;
        case true:
        {
            theory_level = new unsigned int[total_tasks];
            for(unsigned int task_counter = 0; task_counter < total_tasks; ++task_counter)
            {
                std::string level_counter = "level"
                                          + tools::convert<std::string>(task_counter + 1)
                                          + "=";
                theory_level[task_counter] = theory_database(read_preference(level_counter,
                                                                             tools::pattern_length(level_counter),
                                                                             DEFAULT_THEORY_LEVEL));
            }
        }
        break;
    }
}
