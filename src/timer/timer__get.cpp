#include "timer.hpp"
//
//
//
std::string timer::get(unsigned int option, 
                       unsigned int measurement_number)
{
    if((measurement_number > 0) and (measurement_number <= counter))
    {
        switch(option)
        {
            case   WALL_TIME: return wall_time[measurement_number];   break;
            case SYSTEM_TIME: return system_time[measurement_number]; break;
            case   USER_TIME: return user_time[measurement_number];   break;
            case   CPU_USAGE: return cpu_usage[measurement_number];   break;
            case  TIMER_NAME: return name; break;
                     default: return "";
        }
    }
    else
    {
        measurement_number = counter;
        switch(option)
        {
            case   WALL_TIME: return wall_time[measurement_number];   break;
            case SYSTEM_TIME: return system_time[measurement_number]; break;
            case   USER_TIME: return user_time[measurement_number];   break;
            case   CPU_USAGE: return cpu_usage[measurement_number];   break;
            case  TIMER_NAME: return name; break;
                     default: return "";
        }
    }
}
