//
//
//
inline void start()
{
    if(stopped)
    {
        stopped = false;
        counter++;
        chronometer.boost::timer::cpu_timer::start();
    }
};
