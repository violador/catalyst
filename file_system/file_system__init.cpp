#include "file_system.hpp"
//
//
//
void file_system::init(std::string given_filename, std::string given_pathname)
{
    if(given_filename != "")
    {
        filename = given_filename;
        no_file = false;
    }
    else
    {
        filename = "";
        no_file = true;
    }
    boost::filesystem::path file(given_pathname + given_filename);
    status = boost::filesystem::status(file); 
    #pragma omp parallel sections num_threads(6)
    {
        #pragma omp section
        {
            if(file.boost::filesystem::path::has_root_path())
            {
                boost::filesystem::path temp_root_path = file.boost::filesystem::path::root_path();
                root_path = temp_root_path.boost::filesystem::path::string();
            }
            else
            {
                root_path = "";
            }
        }
        #pragma omp section
        {
            if(file.boost::filesystem::path::has_parent_path())
            {
                boost::filesystem::path temp_parent_path = file.boost::filesystem::path::parent_path();
                parent_path = temp_parent_path.boost::filesystem::path::string();
            }
            else
            {
                parent_path = "";
            }
        }
        #pragma omp section
        {
            if(file.boost::filesystem::path::has_relative_path())
            { 
                boost::filesystem::path temp_relative_path = file.boost::filesystem::path::relative_path();
                relative_path = temp_relative_path.boost::filesystem::path::string();
            }
            else
            {
                relative_path = "";
            }
        }
        #pragma omp section
        {
            if(!no_file)
            {
                boost::filesystem::path temp_filename(given_pathname + given_filename);
                temp_filename = file.boost::filesystem::path::extension();
                file_extension = temp_filename.boost::filesystem::path::string();
            }
            else
            {
                file_extension = "";
            }
        }
        #pragma omp section
        {
            exists()? no_valid_path = false : no_valid_path = true;
        }
        #pragma omp section
        {
            fstream_created = false;
        }
    }
}
