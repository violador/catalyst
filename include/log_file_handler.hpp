#ifndef __LOG_FILE_HANDLER_HPP
#define __LOG_FILE_HANDLER_HPP
#include "globals.hpp"
#include "settings.hpp"
#include "file_system.hpp"
//
//
//
struct log_file_handler
{
private:
//
//  Declaring the data members:
    settings *config;          // A pointer-object to link with any object of settings type.
    file_system *file_manager; // A pointer-object to link with any object of file_system type.
    std::fstream log_file;     // The internal fstream object to write the log file.
    bool log_file_ready;       // The fstream object creation state. True if created, false otherwise.
//
public:
//
//  Struct identifier:
    static const int id = 12659;
//
//  Declaring the class constructor:
    log_file_handler();
//
//  Declaring the class constructor:
    log_file_handler(settings &runtime_setup);
//
//  Declaring the class copy constructor:
    log_file_handler(log_file_handler &given_log_file);
//
//
    #include "log_file_handler__operator.cpp"
//
//
    std::fstream output;
//
//  init_log_file(): To start the log file if it not exists yet.
    void init_log_file();
//
//  report(): A set of overloaded template member functions to write on the log file.
//            The report() member function accepts until 10 arguments of any standard
//            type.
    #include "log_file_handler__report.cpp"
//
//
    #include "log_file_handler__exists.cpp"    
};
#endif
