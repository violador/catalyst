#include "settings.hpp"
//
//
//
std::string settings::filename_of(const unsigned int option)
{
    switch(option)
    {    
        case 1: return log_filename;   break;
        case 2: return input_filename; break;
       default: return DEFAULT_NO_FILENAME;
    }    
}
