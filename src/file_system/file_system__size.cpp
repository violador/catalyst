#include "file_system.hpp"
//
//
//
double file_system::size()
{
    switch(exists())
    {
        case false:
        {
            return 0.0;
        }
        break;
        case true:
        {
            boost::filesystem::path file(root_path + relative_path);
            return boost::filesystem::file_size(file);
        }
        break;
    }
}
