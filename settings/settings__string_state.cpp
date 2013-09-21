#include "settings.hpp"
//
//
//
std::string settings::string_state(bool state)
{
    if(state == true)
    {
        return "on";
    }
    else
    {
        return "off";
    }
}
