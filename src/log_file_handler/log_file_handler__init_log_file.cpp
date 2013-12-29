#include "log_file_handler.hpp"
//
//
// 
void log_file_handler::init_log_file()
{
    #pragma omp critical
    switch(not file_manager -> exists()
           and config -> state_of(option::output_mode) 
           and log_file_ready)
    {
        case true:
//
        set_fixed();
        log_file << "\nCatalyst ver. "
                 << CATALYST_VERSION
                 << "\n- Compilation number = "
                 << COMPILATION_NUMBER
                 << std::endl;
//
        write_title_bar("General settings", 80);
        log_file << "- Invoked in                          = "
                 << config -> dir_path_of(option::work)
                 << "\n- By                                  = "
                 << config -> check_current_username()
                 << "\n- From                                = "
                 << config -> check_current_hostname()
                 << "\n- At                                  = "
                 << config -> check_current_time()
                 << "- Number of tasks requested           = "
                 << config -> number_of(option::tasks)
                 << "\n- Memory available at the starting up = "
                 << config -> check_current_memory(option::free)*KILOBYTE_TO_GIGABYTE 
                 << " of " 
                 << config -> check_current_memory(option::total)*KILOBYTE_TO_GIGABYTE
                 << " GB"
                 << "\n- Number of CPUs available            = "
                 << config -> check_current_cpus()
                 << "\n- Log file                            = "
                 << config -> control_key_of(config -> state_of(option::output_mode))
                 << "\n- Log filename                        = "
                 << config -> filename_of(option::log_file)
                 << "\n- High-end mode                       = "
                 << config -> control_key_of(config -> state_of(option::highend_mode))
                 << "\n- Standby mode                        = " 
                 << config -> control_key_of(config -> state_of(option::standby_mode))
                 << "\n- Debug mode                          = " 
                 << config -> control_key_of(config -> state_of(option::debug_mode)) 
                 << "\n- Scratch directory                   = "
                 << config -> dir_path_of(option::scratch)
                 << "\n- SCF convergence criteria            = "
                 << config -> scf_convergence_criteria()
                 << "\n- Numeric precision                   = " 
                 << config -> numeric_precision()
                 << "/"
                 << MAX_PRECISION 
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
                 << "\n" << std::endl;
//
        break;
    }
}
