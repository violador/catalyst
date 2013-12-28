#include "timer.hpp"
//
//
//
void timer::init(std::string given_name)
{
    config = &global_settings::config;
    #pragma omp parallel sections num_threads(3)
    {
        #pragma omp section
        {
            stopped = true;
        }
        #pragma omp section
        {
            counter = 0;
        }
        #pragma omp section
        {
            name = given_name;
        }
    }
}
