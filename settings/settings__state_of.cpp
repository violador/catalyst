#include "settings.hpp"
//
//
//
bool settings::state_of(const unsigned int option)
{
    switch(option)
    {
        case 1: return output_mode_on;      break;
        case 2: return vibration_mode_on;   break;
        case 3: return rotation_mode_on;    break;
        case 4: return translation_mode_on; break;
        case 5: return debug_mode_on;       break;
        case 6: return highend_mode_on;     break;
        case 7: return standby_mode_on;     break;
       default: return false;
    }
}
