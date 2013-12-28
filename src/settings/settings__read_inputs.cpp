#include "settings.hpp"
//
//
//
void settings::read_inputs()
{
    switch(total_tasks >= 1)
    {
        case false:
        {
            input_filename = new std::string[1];
            input_filename[0] = DEFAULT_NO_FILENAME;
        }
        break;
        case true:
        {
            input_filename = new std::string[total_tasks];
            for(unsigned int task_counter = 1; task_counter <= total_tasks; ++task_counter)
            {
                std::string input_counter = "input"
                                          + tools::convert<std::string>(task_counter)
                                          + "=";
                input_filename[task_counter - 1] = read_preference(input_counter,
                                                                   tools::pattern_length(input_counter),
                                                                   DEFAULT_NO_FILENAME);
            }
        }
        break;
    }
}
