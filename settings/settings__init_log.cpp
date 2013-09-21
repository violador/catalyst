#include "settings.hpp"
//
//
//  Defining the settings member function to init the log file: 
void settings::init_log()
{
    if(output_mode_on)
    {
        std::ofstream log_file(log_filename.c_str(), std::ios::out);
        if(log_file.is_open() && log_file.good())
        {
            log_file << "\nCatalyst ver. "
                     << CATALYST_VERSION
                     << "\n- Compilation number = "
                     << COMPILATION_NUMBER
                     << "\n"
                     << "\n== Settings =============================================================================\n"
                     << "\n- Invoked in                                = " << work_dir
                     << "\n- By                                        = " << check_username()
                     << "\n- From                                      = " << check_hostname()
                     << "\n- At                                        = " << check_time()
                     << "- Number of tasks requested                 = " << total_tasks
                     << "\n- Number of total molecular systems defined = " << total_molecular_sys << " (" << total_atoms << " atoms)"
                     << "\n- Memory available at the starting up       = " << check_memory(1) << " of " << check_memory(2) << " bytes"
                     << "\n- Number of CPUs available                  = " << check_number_of_cpus()
                     << "\n- Log file                                  = " << control_key_of(output_mode_on)
                     << "\n- Log filename                              = " << log_filename
                     << "\n- High-end mode                             = " << control_key_of(highend_mode_on)
                     << "\n- Standby mode                              = " << control_key_of(standby_mode_on)
                     << "\n- Debug mode                                = " << control_key_of(debug_mode_on) 
                     << "\n- Vibration mode                            = " << control_key_of(vibration_mode_on) 
                     << "\n- Rotation mode                             = " << control_key_of(rotation_mode_on)  
                     << "\n- Translation mode                          = " << control_key_of(translation_mode_on)  
                     << "\n- Scratch directory                         = " << scratch_dir
                     << "\n- SCF convergence criteria                  = " << scf_criteria
                     << "\n- Numeric precision                         = " << num_precision  << "/10" << std::endl;
            log_file.close();
            logfile_ready = true;
        }
        else
        {
            log_file.close();
            logfile_ready = false;
        }
    }
}
