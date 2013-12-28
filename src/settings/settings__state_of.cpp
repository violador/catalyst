//
//
//
inline bool state_of(const unsigned int option)
{
    switch(option)
    {
        case      option::output_mode: return output_mode_on;      break;
        case   option::vibration_mode: return vibration_mode_on;   break;
        case  option::rotational_mode: return rotation_mode_on;    break;
        case option::translation_mode: return translation_mode_on; break;
        case       option::debug_mode: return debug_mode_on;       break;
        case     option::highend_mode: return highend_mode_on;     break;
        case     option::standby_mode: return standby_mode_on;     break;
        case option::temp_files_usage: return temp_files_on;       break;
        case option::logging_matrices: return logging_matrices;    break;
                              default: return false; break;
    }
};
