#include "file_system.hpp"
//
//
//
void file_system::open_bin_output(std::fstream &file)
{
    switch(no_file)
    {
        case false:
        std::string temp_filename = root_path + relative_path;
//
        file.std::fstream::open(temp_filename.c_str(), 
                                std::fstream::out | std::ios::binary | std::ios::app);
//
        switch(file.std::fstream::is_open() and file.std::fstream::good())
        {
            case true: fstream_created = true; break;
        }
        break;
    }
}
//
//
//
void file_system::open_bin_output(FILE *file)
{
    switch(no_file)
    {
        case false:
        std::string temp_filename = root_path + relative_path;
//
        file = fopen(temp_filename.std::string::c_str(), "w");
//
        switch(file not_eq NULL)
        {
            case true: fstream_created = true; break;
        }
        break;
    }
}
//
//
//
void file_system::open_bin_output()
{
    switch(no_file)
    {
        case false:
        std::string temp_filename = root_path + relative_path;
//
        output.std::fstream::open(temp_filename.c_str(), 
                                  std::fstream::out | std::ios::binary | std::ios::app);
//
        switch(output.std::fstream::is_open() and output.std::fstream::good())
        {
            case true: fstream_created = true; break;
        }
        break;
    }
}
