#include "file_system.hpp"
//
//
//
void file_system::open_txt_input(std::fstream &file)
{
    std::string temp_filename = root_dir() + relative_dir();
//
    file.std::fstream::open(temp_filename.std::string::c_str(), 
                            std::fstream::in);
//
    switch(file.std::fstream::is_open() and file.std::fstream::good())
    {
        case true: stream_ready = true; break;
    }
}
//
//
//
void file_system::open_txt_input()
{
    std::string temp_filename = root_dir() + relative_dir();
//
    input_file.std::fstream::open(temp_filename.std::string::c_str(), 
                                  std::fstream::in);
//
    switch(input_file.std::fstream::is_open() and input_file.std::fstream::good())
    {
        case true: stream_ready = true; break;
    }
}
