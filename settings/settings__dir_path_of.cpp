#include "settings.hpp"
//
//
//
std::string settings::dir_path_of(const unsigned int option)
{
    switch(option)
    {
        case 1: return scratch_dir; break;
        case 2: return work_dir;    break;
       default: return "";
    }
}
