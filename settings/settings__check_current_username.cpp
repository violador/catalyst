#include "settings.hpp"
//
//
//
std::string settings::check_current_username()
{
    #ifdef LINUX
    char *char_type_username;
    char_type_username = getenv("LOGNAME");
    std::stringstream converter_type;
    std::string string_type_username;
    converter_type << char_type_username;
    converter_type >> string_type_username;
    return string_type_username;
    #endif
    #ifdef WIN32
    return "";
    #endif
    #ifdef OSX
    return "";
    #endif
}
