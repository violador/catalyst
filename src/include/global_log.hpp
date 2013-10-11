// ../src/include/global_log.hpp -------------------------------------------------------- //
//
// File author: Humberto Jr. 
//
// Date: 09/2013
//
// Description: The global_log_.hpp declares a global variable called file 
//              of log_file_handler type that should be used by any class. 
//              The object lives inside the global_log namespace to avoid 
//              problems of overlap any other local object named file. To 
//              acess the global_log::file from any place, just include 
//              this header file. This global variable is a rule exception 
//              and globals things must be not used at all.
//
// References:
//
// ------------------------------------------------------------------------------------- //
#ifndef __GLOBAL_LOG_HPP
    #define __GLOBAL_LOG_HPP
    #include "settings.hpp"
    #include "log_file_handler.hpp"
//
//
//
namespace global_log
{
    extern log_file_handler file;
}
#endif
