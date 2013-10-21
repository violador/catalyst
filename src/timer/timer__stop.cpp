//
//
//
inline void stop()
{
    if(not stopped)
    {
        chronometer.boost::timer::cpu_timer::stop();
        #pragma omp parallel sections num_threads(5)
        {
            #pragma omp section
            {
                stopped = true;
            }
            #pragma omp section
            {
                wall_time.insert(i,
                                 std::pair<int, std::string>(counter,
                                                             boost::timer::format(chronometer.boost::timer::cpu_timer::elapsed(),
                                                                                  (short int) DEFAULT_TIMER_LENGTH,
                                                                                  "%w")));
            }
            #pragma omp section
            {
                system_time.insert(j,
                                   std::pair<int, std::string>(counter,
                                                               boost::timer::format(chronometer.boost::timer::cpu_timer::elapsed(),
                                                                                    (short int) DEFAULT_TIMER_LENGTH,
                                                                                    "%s")));
            }
            #pragma omp section
            {
                user_time.insert(m,
                                 std::pair<int, std::string>(counter,
                                                             boost::timer::format(chronometer.boost::timer::cpu_timer::elapsed(),
                                                                                  (short int) DEFAULT_TIMER_LENGTH,
                                                                                  "%u")));
            }
            #pragma omp section
            {
                cpu_usage.insert(n,
                                 std::pair<int, std::string>(counter,
                                                             boost::timer::format(chronometer.boost::timer::cpu_timer::elapsed(),
                                                                                  (short int) DEFAULT_TIMER_LENGTH,
                                                                                  "%p")));
            }
        }
    } // if(not stopped)
};
