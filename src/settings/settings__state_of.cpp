//
//
//
inline bool state_of(const unsigned int option)
{
    switch(option)
    {
        case      OUTPUT_MODE: return output_mode_on;      break;
        case   VIBRATION_MODE: return vibration_mode_on;   break;
        case  ROTATIONAL_MODE: return rotation_mode_on;    break;
        case TRANSLATION_MODE: return translation_mode_on; break;
        case       DEBUG_MODE: return debug_mode_on;       break;
        case     HIGHEND_MODE: return highend_mode_on;     break;
        case     STANDBY_MODE: return standby_mode_on;     break;
        case TEMP_FILES_USAGE: return temp_files_on;       break;
                      default: return false;
    }
};
