#include "periodic_table.hpp"
//
//
//
double periodic_table::mass(const unsigned int element)
{
    if((element > 0) && (element <= total_elements))
    {
        periodic_table::database(element);
        return element_mass;
    }
    return 0.0;
}
