#include <iostream>
#include <string>
#include "periodic_table.hpp"
//
//
//
std::string periodic_table::name(const unsigned int &element)
{
    if((element > 0) && (element <= total_elements))
    {
        periodic_table::database(element);
        return element_name;
    }
    return 0;
}
