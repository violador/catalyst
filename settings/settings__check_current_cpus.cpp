#include "settings.hpp"
//
//
//
unsigned int settings::check_current_cpus()
{
    #ifdef LINUX
    return sysconf(_SC_NPROCESSORS_CONF);
    #endif
}
