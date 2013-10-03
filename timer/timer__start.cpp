//
//
//
inline void start()
{
    if(stopped)
    {
        chronometer.boost::timer::cpu_timer::start();
        stopped = false;
        counter++;
    }
};
