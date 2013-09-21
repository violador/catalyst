#ifndef __FILE_SYSTEM_HANDLER_HPP
#define __FILE_SYSTEM_HANDLER_HPP
#include "globals.hpp"
//
//
//
class file_system_handler
{
private:
//
//
    settings *runtime_setup;
    std::string filename;
    std::string root_path;
    std::string parent_path;
    std::string relative_path; 
    std::string file_extension;
    boost::filesystem::file_status status;
    bool no_valid_path;
    bool no_file;
    bool ofstream_created;
//
//
public:
//
//
   file_system_handler()
   {
       no_valid_path = true;
       no_file = true;
       ofstream_created = false;
   }
//
//
    file_system_handler(std::string &given_filename, std::string &given_pathname)
    {
        boost::filesystem::path file(given_pathname + given_filename);
        status = boost::filesystem::status(file); 
        if(file_exists())
        {
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
                    if(file.boost::filesystem::path::has_filename())
                    {
                        boost::filesystem::path temp_filename = file.boost::filesystem::path::filename();
                        filename = temp_filename.boost::filesystem::path::string();
                        file_extension = temp_filename.boost::filesystem::path::string();
                        temp_filename = file.boost::filesystem::path::extension();
                        file_extension = temp_filename.boost::filesystem::path::string();
                        no_file = false; 
                    }
                    else
                    {
                        filename = "";
                        no_file = true;
                    }
                }
                #pragma omp section
                {
                    no_valid_path = false;
                }
                #pragma omp section
                {
                    ofstream_created = true;
                }
            }
        }
        else
        {
            filename = "";
            root_path = "";
            parent_path = "";
            relative_path = "";
            file_extension = "";
            no_valid_path = true;
        }
    };
//
//
    void init(std::string &given_filename, std::string &given_pathname)
    {
        boost::filesystem::path file(given_pathname + given_filename);
        status = boost::filesystem::status(file); 
        if(file_exists())
        {
            #pragma omp parallel sections num_threads(5)
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
                    if(file.boost::filesystem::path::has_filename())
                    {
                        boost::filesystem::path temp_filename = file.boost::filesystem::path::filename();
                        filename = temp_filename.boost::filesystem::path::string();
                        temp_filename = file.boost::filesystem::path::extension();
                        file_extension = temp_filename.boost::filesystem::path::string(); 
                        no_file = false;
                    }
                    else
                    {
                        filename = "";
                        no_file = true;
                    }
                }
                #pragma omp section
                {
                    no_valid_path = false;
                }
                #pragma omp section
                {
                    ofstream_created = true;
                }
            }
        }
        else
        {
            filename = "";
            root_path = "";
            parent_path = "";
            relative_path = "";
            file_extension = "";
            no_valid_path = true;
        }
    };
//
//
    std::string extension()
    {
        return file_extension;
    };
//
//
    std::string full_name()
    {
        return root_path + relative_path;
    };
//
//
    bool is_dir()
    {
        return boost::filesystem::is_directory(status);
    };
//
//
    bool is_file()
    {
        return boost::filesystem::is_regular_file(status);
    };
//
//
    bool file_exists()
    {
        return boost::filesystem::exists(status);
    };
//
//
    double size()
    {
        if(file_exists())
        {
            boost::filesystem::path file(root_path + relative_path);
            return boost::filesystem::file_size(file);
        }
        else
        {
            return 0.0;
        }
    };
//
//
    std::string root_dir()
    {
        return root_path;
    };
//
//
    std::string parent_dir()
    {
        return parent_path;
    };
//
//
    std::string relative_dir()
    {
        return relative_path;
    };
//
//
    bool no_such_file()
    {
        return no_valid_path;
    };
//
//
    void open_txt_ofstream(std::ofstream *file)
    {
        if(!no_file)
        {
            std::string temp_filename = root_path + relative_path;
            std::ofstream temp_file(temp_filename.c_str(), std::ios::app);
            if(temp_file.is_open() && temp_file.good())
            {
                ofstream_created = true;
                file = &temp_file;
            }
        }
    };
//
//
    void open_bin_ofstream(std::ofstream *file)
    {
        if(!no_file)
        {
            std::string temp_filename = root_path + relative_path;
            std::ofstream temp_file(temp_filename.c_str(), std::ios::binary | std::ios::app);
            if(temp_file.is_open() && temp_file.good())
            {
                ofstream_created = true;
                file = &temp_file;
            }
        }
    }
//
//
};
#endif
