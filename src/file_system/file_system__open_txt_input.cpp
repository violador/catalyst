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
        switch(file.std::fstream::is_open() and file.std::fstream::good())
        {
            case true:
            fstream_created = true;
            break;
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
        switch(input.std::fstream::is_open() and input.std::fstream::good())
        {
            case true:
            fstream_created = true;
            break;
        }
        break;
    }
}
