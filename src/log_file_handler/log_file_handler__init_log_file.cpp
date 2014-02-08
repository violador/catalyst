// ../src/log_file_handler/log_file_handler__init_log_file.cpp ============================== //
//
// Catalyst Lib is free software:  you can redistribute it and/or modifyit under the terms of
// the GNU General Public License as published bythe Free Software Foundation, either version
// 3 of the License, or(at your option) any later version.
//
// Catalyst Lib is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
// without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with Catalyst Lib.
// If not, see <http://www.gnu.org/licenses/>.
//
// ========================================================================================== //
#include "log_file_handler.hpp"
//
//
// 
void log_file_handler::init_log_file()
{
    #pragma omp critical
    switch(not manager.file_system::exists()
           and config -> output_mode()
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
/*
                 << "\n- High-end mode                       = "
                 << config -> ctrl_key(config -> state_of(option::highend_mode))
                 << "\n- Standby mode                        = " 
                 << config -> ctrl_key(config -> state_of(option::standby_mode))
*/
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
                 #if defined (USE_OMP)
                 << "\n- Open multi-processing               = on"
                 #else
                 << "\n- Open multi-processing               = off"
                 #endif
                 #if defined (USE_MPI)
                 << "\n- Message passing interface           = on"
                 #else
                 << "\n- Message passing interface           = off"
                 #endif
                 << "\n- Settings memory usage               = "
                 << config -> my_size()
                 << " MB"
                 << "\n" << std::endl;
//
        break;
    }
}