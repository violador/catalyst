#include "tools.hpp"
//
//
//
const char* tools::convert_enum(const unsigned int option)
{
    switch(option)
    {
        case basis::STO_1G: return "STO-1G"; break;
        case basis::STO_2G: return "STO-2G"; break;
        case basis::STO_3G: return "STO-3G"; break;
        case basis::STO_6G: return "STO-6G"; break;
                   default: return ""; break;
    }
}
//
//
//
unsigned int tools::convert_enum(const char* option)
{
    if(strcmp(option, "STO-1G"))
    {
        return basis::STO_1G;
    }
    else if(strcmp(option, "STO-2G"))
    {
        return basis::STO_2G;
    }
    else if(strcmp(option, "STO-3G"))
    {
        return basis::STO_3G;
    }
    else if(strcmp(option, "STO-6G"))
    {
        return basis::STO_6G;
    }
    else
    {
        return DEFAULT_BASIS_SET;
    }
}
