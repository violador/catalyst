#include "settings.hpp"
#ifdef LINUX
//
//
//
double settings::check_current_memory(const int option)
{
    struct sysinfo info;
    switch(option)
    {
    case 1:  return info.totalram*info.mem_unit; break;
    case 2:  return info.freeram*info.mem_unit;  break;
    default: return 0; break;
    }
}
#endif
