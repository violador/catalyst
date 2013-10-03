// ../src/include/log_file_handler.hpp ------------------------------------------------- //
//
// File author: Humberto Jr. 
//
// Date: 09/2013
//
// Description: The log file handler defines the data struct of members that 
//              handles the usage of the log file. The overloaded << operat-
//              or is also ready to operate in a variable of log file handl-
//              er type such as an ofstream or fstream object. There are al-
//              so member functions designed to write with all the format 
//              issues already built-in.
//
// References:
//
// ------------------------------------------------------------------------------------- //

#ifndef __LOG_FILE_HANDLER_HPP
    #define __LOG_FILE_HANDLER_HPP
    #include "globals.hpp"
    #include "settings.hpp"
    #include "file_system.hpp"
    #include "tools.hpp"
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
//  init_log_file(): To start the log file if it not exists yet.
    void init_log_file();
//
//  Including the inline/template/public member functions:
    #include "log_file_handler__report.cpp"
    #include "log_file_handler__write.cpp"
    #include "log_file_handler__exists.cpp"    
    #include "log_file_handler__set_scientific_notation.cpp"
    #include "log_file_handler__set_fixed.cpp"
    #include "log_file_handler__set_width.cpp"
    #include "log_file_handler__set_right.cpp"
    #include "log_file_handler__set_left.cpp"
    #include "log_file_handler__set_new_line.cpp"
    #include "log_file_handler__close.cpp"
    #include "log_file_handler__fill_line_with.cpp"
    #include "log_file_handler__write_title_bar.cpp"
    #include "log_file_handler__write_task_title.cpp"
    #include "log_file_handler__timestamp.cpp"
    #include "log_file_handler__operator.cpp"
//
    std::fstream output; // ADVICE: This public data member is already deprecated, do not use it.
//                                  Instead of its usage, try the overloaded operator << in an
//                                  object of type log_file_handler. It will be deleted soon.
//
//                                                                         Humberto Jr. (10/2013)
};
#endif
