#include "file_system.hpp"
//
//
//
void file_system::open_txt_input(std::fstream &file)
{
    switch(no_file)
    {
        case false:
        std::string temp_filename = root_path + relative_path;
        file.std::fstream::open(temp_filename.c_str(), std::fstream::in);
        if(file.std::fstream::is_open() and file.std::fstream::good())
        {
            fstream_created = true;
        }
        break;
    }
}
//
//
//
void file_system::open_txt_input()
{
    switch(no_file)
    {
        case false:
        std::string temp_filename = root_path + relative_path;
        input.std::fstream::open(temp_filename.c_str(), std::fstream::in);
        if(input.std::fstream::is_open() and input.std::fstream::good())
        {
            fstream_created = true;
        }
        break;
    }
}
