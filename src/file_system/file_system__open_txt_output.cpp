#include "file_system.hpp"
//
//
//
void file_system::open_txt_output(std::fstream &file)
{
    std::string temp_filename = root_dir() + relative_dir();
//
    file.std::fstream::open(temp_filename.std::string::c_str(), 
                            std::fstream::out | std::ios::app);
//
    switch(file.std::fstream::is_open() and file.std::fstream::good())
    {
        case true: stream_ready = true; break;
    }
}
//
//
//
void file_system::open_txt_output()
{
    std::string temp_filename = root_dir() + relative_dir();
//
    output_file.std::fstream::open(temp_filename.std::string::c_str(), 
                                   std::fstream::out | std::ios::app);
//
    switch(output_file.std::fstream::is_open() and output_file.std::fstream::good())
    {
        case true: stream_ready = true; break;
    }
}
