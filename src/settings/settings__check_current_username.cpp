// ../src/settings/settings__check_current_username.cpp --------------------------------- //
//
// File author: Humberto Jr. 
//
// Date: 08/2013
//
// Description: The settings's member to check the current user name. This 
//              function may or may not be system-dependent. In such case the 
//              implementation should come enclosed between the respective OS
//              macro.
//
// References:
//
// ------------------------------------------------------------------------------------- //
//
//
//
inline std::string check_current_username()
{
//
    #ifdef LINUX
    return tools::convert<std::string>(getenv("LOGNAME"));
    #endif
//
    #ifdef WIN32
    return "";
    #endif
//
    #ifdef OS_X
    return "";
    #endif
//
};
