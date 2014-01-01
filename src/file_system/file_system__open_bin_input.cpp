#include "file_system.hpp"
//
//
//
void file_system::open_bin_input(std::fstream &file)
{
    switch(exists() and is_file())
    {
        case true:
        std::string temp_filename = root_dir() + relative_dir();
//
        file.std::fstream::open(temp_filename.std::string::c_str(), 
                                std::fstream::in | std::ios::binary | std::ios::app);
//
        switch(file.std::fstream::is_open() and file.std::fstream::good())
        {
            case true: stream_ready = true; break;
        }
        break;
    }
}
//
//
//
void file_system::open_bin_input()
{
    switch(exists() and is_file())
    {
        case true:
        std::string temp_filename = root_dir() + relative_dir();
//
        input_file.std::fstream::open(temp_filename.std::string::c_str(), 
                                      std::fstream::in | std::ios::binary | std::ios::app);
//
        switch(input_file.std::fstream::is_open() and input_file.std::fstream::good())
        {
            case true: stream_ready = true; break;
        }
        break;
    }
}
