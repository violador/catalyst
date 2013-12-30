#include "file_system.hpp"
//
//
//
file_system::file_system(): path(NULL),
                            filename(""),
                            root_path(""),
                            parent_path(""),
                            relative_path(""),
                            file_extension(""),
                            no_valid_path(false),
                            fstream_created(false),
                            no_file(true)
{
}
//
//
//
file_system::file_system(std::string given_filename, 
                         std::string given_pathname): path(NULL),
                                                      filename(""),
                                                      root_path(""),
                                                      parent_path(""),
                                                      relative_path(""),
                                                      file_extension(""),
                                                      no_valid_path(false),
                                                      fstream_created(false),
                                                      no_file(true)
{
    init(given_filename, 
         given_pathname);
}
