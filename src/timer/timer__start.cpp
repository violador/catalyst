//
//
//
inline void start()
{
    switch(stopped)
    {
        case true:
        stopped = false;
        ++counter;
        chronometer.boost::timer::cpu_timer::start();
        break;
    }
};
