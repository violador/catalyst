// ../src/include/globals.hpp ----------------------------------------------------------- //
//
// File author: Humberto Jr. 
//
// Date: 08/2013
//
// Description: The globals.hpp must define the most fundamental configurations and
//              also include the respective libraries used by the Catalyst. These
//              configurations may or may not be changed by the user in the runtime.
//              The only way should be by any outside script in the Catalyst insta-
//              ll process, just before the compilation. Any new library have to be
//              included here in the proper location and the conditional compilati-
//              on must be previously checked by a given macro, if needed. Do not 
//              edit this file if there is any doubt or it may cause an entire bad
//              behavior.
//
// References:
//
// ------------------------------------------------------------------------------------- //
#ifndef __GLOBALS_HPP
    #define __GLOBALS_HPP
//
//  Internal settings:
    #ifdef LINUX
        #define OS_TYPE          "GNU/Linux"
    #elif WIN32
        #define OS_TYPE          "Microsoft Windows"
    #elif OS_X
        #define OS_TYPE          "Apple OS X"
    #endif
//
    #define CATALYST_VERSION     "experimental"     // The current version of the catalyst.
    #define COMPILATION_NUMBER   "experimental"     // A random number to identify the compilation.
    #define USER_CONFIG_FILENAME ".catalystrc"      // The name of the config file.
    #define COMMENT_TAG          "#"                // Tag for comment lines in any input file.
    #define AU_UNIT              "a.u."             // Tag for atomic unit reference.
    #define EV_UNIT              "eV"               // Tag for electron volt unit reference.
    #define ANG_UNIT             "A"                // Tag for angstron unit reference.
    #define S_UNIT               "s"                // Tag for second unit reference.
    #define FS_UNIT              "fs"               // Tag for femtosecond unit reference.
    #define K_UNIT               "K"                // Tag for kelvin unit reference.
    #define PROB_UNIT            "%"                // Tag for probabilty unit reference.
    #define MAX_PRECISION        10                 // Tag for the maximum numeric precision.
    #define DEFAULT_NOT_DEFINED  "not defined"      // The default "not defined" content of some std::string types.
    #define DEFAULT_SCF_CRITERIA 0.00000001         // The default value if the user do not gave it in the config file.
    #define DEFAULT_PRECISION    6                  // The default value if the user do not gave it in the config file.
    #define DEFAULT_TASK_NUMBER  1                  // The default task number when there is no actually multi-tasks.
    #define DEFAULT_ARRAY_NAME   "Unknown array"    // The default array name while the user do not set they own.
    #define DEFAULT_NO_FILENAME  "no such filename" // The default content of std::string filenames for no valid files.
    #define DEFAULT_TIMER_LENGTH 10                 // The default length of time measurements for benchmarks.
    #define DEFAULT_THEORY_LEVEL "STO-3G"           // The default level of theory for ab-initio calculations.
    #define DEFAULT_BASIS_SET    2                  // 
    #define WARNING_MSG_TITLE    "WARNING: "        // The warning mensage title.
    #define ON_KEY_CONTROL       "on"               // The true pattern used in the config file.
    #define OFF_KEY_CONTROL      "off"              // The false pattern used in the config file (not really needed).
    #define BIN_FILE_EXTENSION   ".bin"             // The binary extension.
    #define TXT_FILE_EXTENSION   ".txt"             // The plain text extension.
    #define SPACE_LENGTH         5                  // The space length between numbers, used in the file writer funtions.
    #define ARRAY_INDEX_LENGTH   5                  // The size of the indexes of arrays, used in the file writer functions.
    #define TITLE_BAR_SYMBOL     '='                // The symbol used to design the title bars.
    #define BYTE_TO_KILOBYTE     0.0009765625       // The byte to kilobyte conversion factor, B*(1 kB/1024 B).
    #define BYTE_TO_MEGABYTE     0.000000954        // The byte to megabyte conversion factor, B*(1 MB/1048576 B).
    #define BYTE_TO_GIGABYTE     0.000000000931322575
    #define KILOBYTE_TO_GIGABYTE 0.000000953674316
    #define LINUX_MEMINFO_FILE   "/proc/meminfo"    // The system memory information file.
    #define STO3G_RANGE          53
//
    #ifndef EXIT_SUCCESS
        #define EXIT_SUCCESS     0                  // Tag for success operations.
    #endif
//
    #ifndef EXIT_FAILURE
        #define EXIT_FAILURE     1                  // Tag for fail operations.
    #endif
//
    #ifdef LINUX
        #define DEFAULT_CURRENT_DIR "./"            // The default directory for Unix-like OS.
    #endif
//
//  Levels enum list:
    #define STO3G 1
    #define STO2G 2
    #define STO1G 3
//
//  Orbitals enum list:
    #define SUB_SHELL_s   0
    #define SUB_SHELL_p   1
    #define SUB_SHELL_d   2
    #define SUB_SHELL_f   3
    #define SUB_SHELL_1s  1
    #define SUB_SHELL_2s  2
    #define SUB_SHELL_2px 3
    #define SUB_SHELL_2py 4
    #define SUB_SHELL_2pz 5
//
//  ERI enum list:
    #define INTEGRAL_ssss 1
    #define INTEGRAL_psss 2
    #define INTEGRAL_psps 3
    #define INTEGRAL_ppss 4
//
//  Including C standard headers:
    #include <stdlib.h>
    #include <omp.h>
//
//  Including C++ standard headers:
    #include <iostream>
    #include <cstddef>
    #include <iomanip>
    #include <fstream>
    #include <sstream>
    #include <string>
    #include <typeinfo>
    #include <algorithm>
    #include <ios>
    #include <ctime>
    #include <new>
    #include <cmath>
    #include <map>
//
//  Including GSL headers ("-lgsl" and "-lgslcblas" to linkage):
    #include <gsl/gsl_errno.h>
    #include <gsl/gsl_math.h>
    #include <gsl/gsl_vector.h>
    #include <gsl/gsl_matrix.h>
    #include <gsl/gsl_sf_exp.h>
    #include <gsl/gsl_sf_erf.h>
    #include <gsl/gsl_linalg.h>
    #include <gsl/gsl_eigen.h>
    #include <gsl/gsl_blas.h>
    #include <gsl/gsl_const_num.h>
    #include <gsl/gsl_const_mksa.h>
    #include <gsl/gsl_rng.h>
    #include <gsl/gsl_sf_gamma.h>
//
//  Including Boost C++ headers:
    #include <boost/filesystem.hpp> // "-lboost_filesystem" to linkage.
    #include <boost/timer/timer.hpp>
    #include <boost/lexical_cast.hpp>
    #ifdef USE_MPI
        //#include <boost/mpi.hpp> // "-lboost_mpi" to linkage.
        //#include <boost/mpi/environment.hpp>
        //#include <boost/mpi/communicator.hpp>
        //#include <boost/mpi/nonblocking.hpp>
    #endif
//
//  Including Linux only headers:
    #ifdef LINUX
        #include <sys/sysinfo.h>
        #include <unistd.h>
    #endif
//
//  Includind Windows only headers:
    #ifdef WIN32
        #include <windows.h>
    #endif
//
//  Including OSX only headers:
    #ifdef OS_X
//      Empty, so far.
    #endif
//
//  GSL lib controls:
    #define HAVE_INLINE
    #define GSL_RANGE_CHECK_OFF
//
//  Multi-task/core controls:
    #ifdef USE_OMP
        #define omp_set_nested()
    #else
        #define omp_get_thread_num() 0
    #endif
//
    #ifdef USE_MPI
        #define MASTER_PROCESS 0
    #endif
//
//  Defining enumeration lists:
    namespace orbital
    {
        enum{s, p, d, f};
        enum{_1s, _2s, _2px, _2py, _2pz};
    }
    namespace eri
    {
        enum
        {
            ssss, 
            psss, 
            psps, 
            ppss, 
            ppps, 
            pppp
        };
    }
    namespace option
    {
        enum
        {
//
//          settings::dir_path_of():
            scratch,
            work,
//
//          settings::filename_of():
            log_file,
            input_file,
            config_file,
//
//          settings::state_of():
            output_mode,
            vibration_mode,
            rotational_mode,
            translation_mode,
            debug_mode,
            highend_mode,
            standby_mode,
            temp_files_usage,
            logging_matrices,
//
//          settings::number_of():
            tasks,
//
//          settings::check_current_memory():
            total,
            free,
//
//          array::check_if():
            is_positive,
            is_negative,
            is_null,
            is_constant,
            is_square,
            is_created,
            is_deleted,
            is_transposed,
//
//          timer::get():
            wall_time,
            system_time,
            user_time,
            cpu_usage,
            timer_name,
//
//          tools::random_number():
            taus2, 
            mt19937, 
            ranlxs0, 
            ranlxs2, 
            ranlxd2, 
            ranlux389, 
            gfsr4
        };
    }
    namespace basis
    {
        enum
        {
            STO_1G,
            STO_2G,
            STO_3G,
            STO_6G
        };
    }
#endif
