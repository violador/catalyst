#include "settings.hpp"
//
//
//
settings::settings()
{
    config_file = USER_CONFIG_FILENAME;
    init();
}
//
//
//
settings::settings(const std::string &filename)
{
    config_file = filename;
    init();
}
//
//
//
settings::settings(const char* filename)
{
    config_file = filename;
    init();
}
