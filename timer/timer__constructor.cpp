#include "timer.hpp"
//
//
//
timer::timer()
{
    stopped = true;
    counter = 0;
    name = "";
};
//
//
//
timer::timer(settings &runtime_setup, std::string given_name)
{
    config = &runtime_setup;
    #pragma omp parallel sections num_threads(7)
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
            i = wall_time.begin();
        }
        #pragma omp section
        {
            j = system_time.begin();
        }
        #pragma omp section
        {
            m = user_time.begin();
        }
        #pragma omp section
        {
            n = cpu_usage.begin();
        }
        #pragma omp section
        {
            name = given_name;
        }
    }
};
