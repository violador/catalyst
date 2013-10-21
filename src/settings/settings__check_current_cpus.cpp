// ../src/settings/settings__check_current_cpus.cpp ------------------------------------ //
//
// File author: Humberto Jr. 
//
// Date: 07/2013
//
// Description: The settings's member to check the current number of CPUs. This
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
inline unsigned int check_current_cpus()
{
    #ifdef LINUX
    return sysconf(_SC_NPROCESSORS_CONF);
    #endif
};
