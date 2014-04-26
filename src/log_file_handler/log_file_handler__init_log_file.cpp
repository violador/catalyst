#include "log_file_handler.hpp"
//
//
//
/// @brief A help function used to initialize the log file in the constructor.
//
/// @return None.
//
void log_file_handler::init_log_file()
{
	#pragma omp critical
	switch(!manager.file_system::exists()
	       && config -> output_mode()
	       && log_file_ready)
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
				 << config -> work_dir()
				 << "\n- By                                  = "
				 << config -> check_current_username()
				 << "\n- From                                = "
				 << config -> check_current_hostname()
				 << "\n- At                                  = "
				 << config -> check_current_time()
				 << "- Number of tasks requested           = "
				 << config -> tasks()
				 << "\n- Memory available at the starting up = "
				 << config -> check_free_memory()
				 << " of "
				 << config -> check_total_memory()
				 << " GB"
				 << "\n- Number of CPUs available            = "
				 << config -> check_current_cpus()
				 << "\n- Log file                            = "
				 << config -> ctrl_key(config -> output_mode())
				 << "\n- Log filename                        = "
				 << config -> log_file()
				 << "\n- Debug mode                          = "
				 << config -> ctrl_key(config -> debug_mode())
				 << "\n- Scratch directory                   = "
				 << config -> scratch_dir()
				 << "\n- SCF convergence criteria            = "
				 << config -> scf_convergence_criteria()
				 << "\n- Numeric precision                   = "
				 << config -> numeric_precision()
				 << "/"
				 << tools::max_precision()
				 #if defined(USE_OMP)
				 << "\n- Open multi-processing               = on"
				 #else
				 << "\n- Open multi-processing               = off"
				 #endif
				 #if defined(USE_MPI)
				 << "\n- Message passing interface           = on"
				 #else
				 << "\n- Message passing interface           = off"
				 #endif
				 << "\n- Settings memory usage               = "
				 << tools::kB(config -> my_size())
				 << " kB"
				 << "\n" << std::endl;
		return;
	}
}
