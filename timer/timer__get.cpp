#include "timer.hpp"
//
//
//
std::string timer::get(unsigned int option, unsigned int measurement_number)
{
    if((measurement_number not_eq 0) and (measurement_number <= counter))
    {
        switch(option)
        {
            case 1: return wall_time[measurement_number];   break;
            case 2: return system_time[measurement_number]; break;
            case 3: return user_time[measurement_number];   break;
            case 4: return cpu_usage[measurement_number];   break;
            case 5: return name; break;
           default: return "";
        }
    }
    else
    {
        measurement_number = counter;
        switch(option)
        {
            case 1: return wall_time[measurement_number];   break;
            case 2: return system_time[measurement_number]; break;
            case 3: return user_time[measurement_number];   break;
            case 4: return cpu_usage[measurement_number];   break;
            case 5: return name; break;
           default: return "";
        }
    }
}
