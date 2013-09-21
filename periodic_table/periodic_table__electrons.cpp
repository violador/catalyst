#include "periodic_table.hpp"
//
//
//
unsigned int periodic_table::core_electrons(const unsigned int &element)
{
    if((element > 0) && (element <= total_elements))
    {
        periodic_table::database(element);
        return element_core_electrons;
    }
    return 0;
}
//
//
//
unsigned int periodic_table::valence_electrons(const unsigned int &element)
{
    if((element > 0) && (element <= total_elements))
    {       
        periodic_table::database(element);
        return element_valence_electrons;
    }
    return 0;
}
