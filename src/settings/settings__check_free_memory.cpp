#include "settings.hpp"
//
//
//
double settings::check_free_memory()
{
    std::ifstream file(LINUX_MEMINFO_FILE, std::ios::in);
    switch(file.std::ifstream::is_open() and file.std::ifstream::good())
    {
        case false:
        {
            return 0.0;
        }
        break;
        case true:
        {
            std::string line = "";
            while(getline(file, line))
            {
                switch((bool) line.std::string::compare(0, 8, "MemFree:"))
                {
                    case false:
                    tools::remove_char(line, 'k');
                    tools::remove_char(line, 'B');
                    tools::remove_blank_spaces(line);
                    return tools::convert<double>(line.std::string::erase(0, 8));
                    break;
                }
            }
            file.std::ifstream::close();
            return 0.0;
        }
        break;
    }
}
