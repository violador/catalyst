#include "periodic_table.hpp"
//
//
//
unsigned int periodic_table::type(const std::string symbol)
{
    for(unsigned int i = 1; i <= total_elements; i++)
    {
        if(periodic_table::symbol(i) == symbol)
        {
            return i;
        }
    }
    return 0;
}
