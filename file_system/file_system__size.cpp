#include "file_system.hpp"
//
//
//
double file_system::size()
{
    if(exists())
    {
        boost::filesystem::path file(root_path + relative_path);
        return boost::filesystem::file_size(file);
    }
    else
    {
        return 0.0;
    }
}
