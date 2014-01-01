//
//
//
inline std::string build_slash()
{
    #if defined LINUX
        return tools::convert<std::string>("/");
    #elif defined WIN32
        return tools::convert<std::string>("\\"); 
    #endif
};
