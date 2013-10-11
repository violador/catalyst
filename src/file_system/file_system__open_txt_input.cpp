#include "file_system.hpp"
//
//
//
void file_system::open_txt_input(std::fstream &file)
{
    if(!no_file)
    {
        std::string temp_filename = root_path + relative_path;
        file.std::fstream::open(temp_filename.c_str(), std::fstream::in);
        if(file.is_open() && file.good())
        {
            fstream_created = true;
        }
    }
}
