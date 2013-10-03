#include "error_handler.hpp"
//
//
//
void error_handler::evaluate_behavior(const int &error)
{
    #pragma omp parallel sections num_threads(2)
    {
        #pragma omp section
        {
            if(check_gsl)
            {
                switch(error)
                {
                    case GSL_ENOMEM:
                    {
                        global_log::file.set_new_line;
                        global_log::file << WARNING_MSG_TITLE;
                        global_log::file.write("- No available memory to allocate the array");
                    }
                    break;
                }
            }
        }
        #pragma omp section
        {
            if(check_boost)
            {
            }
        }
    }
}
