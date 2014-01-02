// ../src/include/file_system.hpp -------------------------------------------------------- //
//
// File author: Humberto Jr. 
//
// Date: 07/2013
//
// Description: The file system class defines the type of variables designed to handle
//              given filenames and (optional) pathnames. It will check if the given 
//              path + file, or at least just a file, exists and provide several infos 
//              about it. It can also open the files as plain text or binary. If a fi-
//              le-only is provided, it assumes the path as the current directory.
//
// References: http://www.boost.org/doc/libs/1_54_0/libs/filesystem/doc/index.htm
//
// ------------------------------------------------------------------------------------- //
#ifndef __FILE_SYSTEM_HPP
    #define __FILE_SYSTEM_HPP
    #include "globals.hpp"
    #include "tools.hpp"
//
//
//
class file_system
{
    private:
//
//  Declaring the private data members:
    boost::filesystem::path file;
    boost::filesystem::path path;
    boost::filesystem::path *input;
    boost::filesystem::path *disk_info;
    boost::filesystem::path filename;
    boost::filesystem::path root_path;
    boost::filesystem::path parent_path;
    boost::filesystem::path relative_path;
    boost::filesystem::path file_extension;
    boost::filesystem::file_status file_status;
    boost::filesystem::file_status path_status;
    boost::filesystem::space_info disk_space;
    bool stream_ready;
//
//  Including the inline/template/private member functions:
    #include "file_system__check_filename.cpp"
    #include "file_system__init_file.cpp"
    #include "file_system__init_path.cpp"
    #include "file_system__build_slash.cpp"
    #include "file_system__restart_file.cpp"
    #include "file_system__restart_path.cpp"
//
    public:
//
//  Class identifier:
    static const int id = 18543;
//
//  Declaring the class constructor:
    file_system();
    file_system(const std::string &given_filename, 
                const std::string &given_pathname);
//
//  Declaring the public data members:
    std::fstream input_file;
    std::fstream output_file;
//
//  Declaring the public member functions:
    void open_txt_output(std::fstream &file);
    void open_txt_output();
    void open_txt_input(std::fstream &file);
    void open_txt_input();
    void open_bin_output(std::fstream &file);
    void open_bin_output();
    void open_bin_output(FILE *file);
    void open_bin_input(std::fstream &file);
    void open_bin_input();
//
//  Including the inline/template/public member functions:
    #include "file_system__extension.cpp"
    #include "file_system__full_name.cpp"
    #include "file_system__name.cpp"
    #include "file_system__is_dir.cpp"
    #include "file_system__is_file.cpp"
    #include "file_system__exists.cpp"
    #include "file_system__root_dir.cpp"
    #include "file_system__parent_dir.cpp"
    #include "file_system__relative_dir.cpp"
    #include "file_system__close.cpp"
    #include "file_system__is_open.cpp"
    #include "file_system__my_size.cpp"
    #include "file_system__size.cpp"
    #include "file_system__valid_dir.cpp"
    #include "file_system__check_disk_space.cpp"
    #include "file_system__check_disk_capacity.cpp"
    #include "file_system__rename_file.cpp"
    #include "file_system__rename_dir.cpp"
    #include "file_system__remove_file.cpp"
    #include "file_system__is_link.cpp"
    #include "file_system__init.cpp"
//
};
#endif
