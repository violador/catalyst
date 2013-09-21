#include "settings.hpp"
//
//
//
std::string settings::check_current_hostname()
{
    #ifdef LINUX
    char *char_type_hostname;
    char_type_hostname = getenv("HOSTNAME");
    std::stringstream converter_type;
    std::string string_type_hostname;
    converter_type << char_type_hostname;
    converter_type >> string_type_hostname;
    return string_type_hostname;
    #endif
    #ifdef WIN32
    return "";
    #endif
    #ifdef OSX
    return "";
    #endif
}
