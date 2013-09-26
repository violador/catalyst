#include "log_file_handler.hpp"
//
//
// 
void log_file_handler::init_log_file()
{
    if((not file_manager -> exists()) and config -> state_of(OUTPUT_MODE) and log_file_ready)
    {
        log_file << "\nCatalyst ver. "
                 << CATALYST_VERSION
                 << "\n- Compilation number = "
                 << COMPILATION_NUMBER
                 << "\n"
                 << "\n== General settings =======================================================================\n"
                 << "\n- Invoked in                          = "
                 << config -> dir_path_of(WORK)
                 << "\n- By                                  = "
                 << config -> check_current_username()
                 << "\n- From                                = "
                 << config -> check_current_hostname()
                 << "\n- At                                  = "
                 << config -> check_current_time()
                 << "- Number of tasks requested           = "
                 << config -> number_of(TASKS)
                 << "\n- Memory available at the starting up = "
                 << config -> check_current_memory(1) 
                 << " of " 
                 << config -> check_current_memory(2) 
                 << " bytes"
                 << "\n- Number of CPUs available            = "
                 << config -> number_of(CPUS)
                 << "\n- Log file                            = "
                 << config -> control_key_of(config -> state_of(OUTPUT_MODE))
                 << "\n- Log filename                        = "
                 << config -> filename_of(LOG_FILE)
                 << "\n- High-end mode                       = "
                 << config -> control_key_of(config -> state_of(HIGHEND_MODE))
                 << "\n- Standby mode                        = " 
                 << config -> control_key_of(config -> state_of(STANDBY_MODE))
                 << "\n- Debug mode                          = " 
                 << config -> control_key_of(config -> state_of(DEBUG_MODE)) 
                 << "\n- Scratch directory                   = "
                 << config -> dir_path_of(SCRATCH)
                 << "\n- SCF convergence criteria            = "
                 << config -> scf_convergence_criteria()
                 << "\n- Numeric precision                   = " 
                 << config -> numeric_precision()
                 << "/6" 
                 #ifdef USE_OMP
                 << "\n- Open multi-processing               = on"
                 #else
                 << "\n- Open multi-processing               = off"
                 #endif
                 #ifdef USE_MPI
                 << "\n- Message passing interface           = on"
                 #else
                 << "\n- Message passing interface           = off"
                 #endif
                 << "\n- Settings memory usage               = "
                 << config -> my_size()
                 << " kB"
                 << std::endl;
    } // if(file_manager -> exists() and (not config -> state_of(OUTPUT_MODE)) or (not log_file_ready)) 
}
