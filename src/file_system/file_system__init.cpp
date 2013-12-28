#include "file_system.hpp"
//
//
//
void file_system::init(std::string given_filename, 
                       std::string given_pathname)
{
    switch(given_filename not_eq "")
    {
        case false:
        {
            filename = "";
            no_file = true;
        }
        break;
        case true:
        {
            filename = given_filename;
            no_file = false;
        }
        break;
    }
//
    boost::filesystem::path file(given_pathname + given_filename);
    status = boost::filesystem::status(file); 
//
    #pragma omp parallel sections num_threads(6)
    {
        #pragma omp section
        {
            switch(file.boost::filesystem::path::has_root_path())
            {
                case false:
                {
                    root_path = "";
                }
                break;
                case true:
                {
                    boost::filesystem::path temp_root_path = file.boost::filesystem::path::root_path();
                    root_path = temp_root_path.boost::filesystem::path::string();
                }
                break;
            }
        }
        #pragma omp section
        {
            switch(file.boost::filesystem::path::has_parent_path())
            {
                case false:
                {
                    parent_path = "";
                }
                break;
                case true:
                {
                    boost::filesystem::path temp_parent_path = file.boost::filesystem::path::parent_path();
                    parent_path = temp_parent_path.boost::filesystem::path::string();
                }
                break;
            }
        }
        #pragma omp section
        {
            switch(file.boost::filesystem::path::has_relative_path())
            {
                case false:
                {
                    relative_path = "";
                }
                break;
                case true:
                {
                    boost::filesystem::path temp_relative_path = file.boost::filesystem::path::relative_path();
                    relative_path = temp_relative_path.boost::filesystem::path::string();
                }
                break;
            }
        }
        #pragma omp section
        {
            switch(no_file)
            {
                case false:
                {
                    boost::filesystem::path temp_filename(given_pathname + given_filename);
                    temp_filename = file.boost::filesystem::path::extension();
                    file_extension = temp_filename.boost::filesystem::path::string();
                }
                break;
                case true:
                {
                    file_extension = "";
                }
                break;
            }
        }
        #pragma omp section
        {
            switch(boost::filesystem::exists(status))
            {
                case false:
                {
                    no_valid_path = true;
                }
                break;
                case true:
                {
                    no_valid_path = false;
                }
                break;
            }
        }
        #pragma omp section
        {
            fstream_created = false;
        }
    }
}
