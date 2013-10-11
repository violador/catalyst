#include "file_system.hpp"
//
//
//
void file_system::open_txt_output(std::fstream &file)
{
    if(not no_file)
    {
        std::string temp_filename = root_path + relative_path;
        file.std::fstream::open(temp_filename.c_str(), std::fstream::out | std::ios::app);
        if(file.is_open() && file.good())
        {
            fstream_created = true;
        }
    }
}
