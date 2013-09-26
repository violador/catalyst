#ifndef __GLOBALS_HPP
    #define __GLOBALS_HPP
//
//  Internal settings:
//
    #ifdef LINUX
        #define OS_TYPE          "GNU/Linux"
    #elif WIN32
        #define OS_TYPE          "Microsoft Windows"
    #elif OS_X
        #define OS_TYPE          "Apple OS X"
    #endif
//
    #define CATALYST_VERSION     "experimental" // The current version of the catalyst.
    #define COMPILATION_NUMBER   "experimental" // A random number to identify the compilation.
    #define USER_CONFIG_FILENAME ".catalystrc"  // The name of the user's preferences file.
    #define COMMENT_TAG          "#"            // Tag for comment lines in any input file.
    #define AU_UNIT              "a.u."         // Tag for atomic unit reference.
    #define EV_UNIT              "eV"           // Tag for electron volt unit reference.
    #define ANG_UNIT             "A"            // Tag for angstron unit reference.
    #define S_UNIT               "s"            // Tag for second unit reference.
    #define FS_UNIT              "fs"           // Tag for femtosecond unit reference.
    #define K_UNIT               "K"            // Tag for kelvin unit reference.
    #define PROB_UNIT            "%"            // Tag for probabilty unit reference.
    #define MAX_PRECISION        10             // Tag for the maximum numeric precision.
    #define DEFAULT_NOT_DEFINED  "not defined"
    #define DEFAULT_SCF_CRITERIA 0.00000001
    #define DEFAULT_PRECISION    6
    #define DEFAULT_TASK_NUMBER  1
    #define DEFAULT_ARRAY_NAME   "Unknown array"
    #define ON_KEY_CONTROL       "on"
    #define OFF_KEY_CONTROL      "off"
    #define BIN_FILE_EXTENSION   ".bin"
    #define TXT_FILE_EXTENSION   ".txt"
    #define SPACE_LENGTH         5    
    #define TITLE_BAR_SYMBOL     '='
    #define BYTE_TO_KILOBYTE     0.0009765625
//
    #ifndef EXIT_SUCCESS
        #define EXIT_SUCCESS     0              // Tag for success operations.
    #endif
//
    #ifndef EXIT_FAILURE
        #define EXIT_FAILURE     1              // Tag for fail operations.
    #endif
//
    #ifdef LINUX
        #define DEFAULT_CURRENT_DIR "./"
    #endif
//
//  Including C standard headers:
    #include <stdlib.h>
    #include <math.h>
    #ifdef USE_OMP
        #include <omp.h>
    #endif
//
//  Including C++ standard headers:
    #include <iostream>
    #include <iomanip>
    #include <fstream>
    #include <sstream>
    #include <string>
    #include <algorithm>
    #include <cctype>
    #include <ios>
    #include <ctime>
    #include <new>
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
    #include <gsl/gsl_ntuple.h>
//
//  Including Boost C++ headers:
    #include <boost/filesystem.hpp> // "-lboost_filesystem" to linkage.
//  #include <boost/signals2.hpp>
    #ifdef USE_MPI
        #include <boost/mpi.hpp> // "-lboost_mpi" to linkage.
        #include <boost/mpi/environment.hpp>
        #include <boost/mpi/communicator.hpp>
        #include <boost/mpi/nonblocking.hpp>
    #endif
    #include <boost/preprocessor/repetition/enum_params.hpp>
    #include <boost/preprocessor/iteration/local.hpp>
    #include <boost/preprocessor/repetition/repeat.hpp>
//
//  Including Linux only headers:
    #ifdef LINUX
        #include <sys/sysinfo.h>
        #include <unistd.h>
    #endif
//
//  Includind Windows only headers:
    #ifdef WIN32
//      Empty, so far.
    #endif
//
//  Including OSX only headers:
    #ifdef OS_X
//      Empty, so far.
    #endif
//
//  GSL lib controls:
//
    #define HAVE_INLINE
    #define GSL_RANGE_CHECK_OFF
//
//  Multi-task/core controls:
//
    #ifndef USE_OMP
        #define omp_get_thread_num() 0
    #endif
//
    #ifdef USE_MPI
        #define MASTER_PROCESS 0
    #endif
//
#endif
