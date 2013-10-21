#include "file_system.hpp"
//
//
//
void file_system::open_txt_output(std::fstream &file)
{
    switch(no_file)
    {
        case false:
        std::string temp_filename = root_path + relative_path;
        file.std::fstream::open(temp_filename.c_str(), std::fstream::out | std::ios::app);
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
void file_system::open_txt_output()
{
    switch(no_file)
    {
        case false:
        std::string temp_filename = root_path + relative_path;
        output.std::fstream::open(temp_filename.c_str(), std::fstream::out | std::ios::app);
        if(output.std::fstream::is_open() and output.std::fstream::good())
        {
            fstream_created = true;
        }
        break;
    }
}
