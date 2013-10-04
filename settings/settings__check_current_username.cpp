//
//
//
inline std::string check_current_username()
{
//
    #ifdef LINUX
//
    tools convert;
    return convert.to_string_from(getenv("LOGNAME"));
//
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
