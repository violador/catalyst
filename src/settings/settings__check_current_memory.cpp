// ../src/settings/settings__check_current_memory.cpp ---------------------------------- //
//
// File author: Humberto Jr. 
//
// Date: 06/2013
//
// Description: The settings's member to check the current available memory 
//              and the total memory in kB. This function may or may not be 
//              system-dependent. In such case the implementation should 
//              come enclosed between the respective OS macro. So far the 
//              Linux version just checks the /proc/meminfo file, since the
//              libraries that handle such task seems do not behave well.
//
// References:
//
// ------------------------------------------------------------------------------------- //
//
//
//
#ifdef LINUX
inline double check_current_memory(const unsigned int option)
{
    switch(option)
    {
        case option::total: return check_total_memory(); break;
        case  option::free: return check_free_memory();  break;
    }
    return 0.0;
};
#endif
