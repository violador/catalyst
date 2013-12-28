// ../src/settings/settings__check_current_time.cpp ------------------------------------- //
//
// File author: Humberto Jr. 
//
// Date: 10/2013
//
// Description: The settings's member to check the current time in the following 
//              format: Sat Oct 12 00:24:17 2013. 
//
// References:
//
// ------------------------------------------------------------------------------------- //

//
//
//
inline std::string check_current_time()
{
    time_t current_time = time(0);
    return tools::convert<std::string>(ctime(&current_time));
};
