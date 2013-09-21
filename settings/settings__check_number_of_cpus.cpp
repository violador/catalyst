#include "settings.hpp"
//
//
//
unsigned int settings::check_number_of_cpus()
{
    #ifdef LINUX
    return sysconf(_SC_NPROCESSORS_CONF);
    #endif
}
