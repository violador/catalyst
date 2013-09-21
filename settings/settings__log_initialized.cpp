#include "settings.hpp"
//
//
//  Defining the settings member function to check if the log file are initialized: 
bool settings::log_initialized()
{
    return logfile_ready;
//
// The piece of code below was the first version of this member function.
// But it is deprecated already in order to decrease the I/O operations.
// Nowdays, just one bool variable defined in the init_log() is enough to
// handle this simple task.
//                                                 Humberto Jr. (08/2013)
//
/*   
    std::ofstream log_file(log_filename.c_str(), std::ios::in);
    if(log_file.good())
    {
        log_file.close();
        return true;
    }
    else
    {
        log_file.close();
        return false;
    }
*/
}
