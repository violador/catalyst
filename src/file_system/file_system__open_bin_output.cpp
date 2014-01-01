#include "file_system.hpp"
//
//
//
void file_system::open_bin_output(std::fstream &file)
{
    switch(exists() and is_file())
    {
        case true:
        std::string temp_filename = root_dir() + relative_dir();
//
        file.std::fstream::open(temp_filename.std::string::c_str(), 
                                std::fstream::out | std::ios::binary | std::ios::app);
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
void file_system::open_bin_output(FILE *file)
{
    switch(exists() and is_file())
    {
        case true:
        std::string temp_filename = root_dir() + relative_dir();
//
        file = fopen(temp_filename.std::string::c_str(), "w");
//
        switch(file not_eq NULL)
        {
            case true: stream_ready = true; break;
        }
        break;
    }
}
//
//
//
void file_system::open_bin_output()
{
    switch(exists() and is_file())
    {
        case true:
        std::string temp_filename = root_dir() + relative_dir();
//
        output_file.std::fstream::open(temp_filename.std::string::c_str(), 
                                       std::fstream::out | std::ios::binary | std::ios::app);
//
        switch(output_file.std::fstream::is_open() and output_file.std::fstream::good())
        {
            case true: stream_ready = true; break;
        }
        break;
    }
}
