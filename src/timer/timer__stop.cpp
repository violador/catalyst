#include "timer.hpp"
//
//
//
void timer::stop()
{
    switch(stopped)
    {
        case false:
        chronometer.boost::timer::cpu_timer::stop();
        std::string w = boost::timer::format(chronometer.boost::timer::cpu_timer::elapsed(),
                                                           (short int) DEFAULT_TIMER_LENGTH,
                                                                                        "%w");
        std::string s = boost::timer::format(chronometer.boost::timer::cpu_timer::elapsed(),
                                                           (short int) DEFAULT_TIMER_LENGTH,
                                                                                        "%s");
        std::string u = boost::timer::format(chronometer.boost::timer::cpu_timer::elapsed(),
                                                           (short int) DEFAULT_TIMER_LENGTH,
                                                                                        "%u");
        std::string c = boost::timer::format(chronometer.boost::timer::cpu_timer::elapsed(),
                                                           (short int) DEFAULT_TIMER_LENGTH,
                                                                                        "%p");
        #pragma omp parallel sections num_threads(5)
        {
            #pragma omp section
            {
                wall_time.insert(std::pair<unsigned int, std::string>(counter, w));
            }
            #pragma omp section
            {
                system_time.insert(std::pair<unsigned int, std::string>(counter, s));
            }
            #pragma omp section
            {
                user_time.insert(std::pair<unsigned int, std::string>(counter, u));
            }
            #pragma omp section
            {
                cpu_usage.insert(std::pair<unsigned int, std::string>(counter, c));
            }
            #pragma omp section
            {
                stopped = true;
            }
        }
        break;
    }
};
