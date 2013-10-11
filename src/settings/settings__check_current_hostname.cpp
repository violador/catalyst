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
