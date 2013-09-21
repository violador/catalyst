#include "settings.hpp"
//
//
//
unsigned int settings::number_of(unsigned int option)
{
    switch(option)
    {
    case 1:  return total_tasks; break;
    case 2:  return total_molecular_sys; break; 
    case 3:  return total_atoms; break;
    case 4:  return check_number_of_cpus(); break;
    default: return 0;
    }
}
