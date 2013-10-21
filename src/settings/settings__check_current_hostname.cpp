// ../src/settings/settings__check_current_hostname.cpp --------------------------------- //
//
// File author: Humberto Jr. 
//
// Date: 07/2013
//
// Description: The settings's member to check the current PC name. This fun-
//              ction may or may not be system-dependent. In such case the 
//              implementation should come enclosed between the respective OS
//              macro.
//
// References:
//
// ------------------------------------------------------------------------------------- //
//
//
//
inline int check_current_hostname()
{
//
    #ifdef LINUX
    return gethostid();
    #endif
//
    #ifdef WIN32
    return 0;
    #endif
//
    #ifdef OS_X
    return 0;
    #endif
//
};
