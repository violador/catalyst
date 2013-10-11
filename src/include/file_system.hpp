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
//
//
//
class file_system
{
private:
//
//  Declaring the data members:
    std::string filename;                  // The filename, if any.
    std::string root_path;                 // The root directory path of the current full path.
    std::string parent_path;               // The parent directory path of the current full path.
    std::string relative_path;             // The relative directory path of the current full path.
    std::string file_extension;            // The file extension, if any.
    boost::filesystem::file_status status; // The status of the current path and file, if any.
    bool no_valid_path;                    // The path state, true if a no valid path is given. False otherwise.
    bool no_file;                          // The file state, true if there is no file. False otherwise.
    bool fstream_created;                  // The fstream creation state, true if a fstream file was created. False otherwise.
public:
//
//  Class identifier:
    static const int id = 18543;
//
//  Declaring the class constructor:
    file_system(std::string given_filename = "", std::string given_pathname = DEFAULT_CURRENT_DIR);
//
//  init(): To initialize the class if needed (a constructor copy).
    void init(std::string given_filename = "", std::string given_pathname = DEFAULT_CURRENT_DIR);
//
//  size(): To return the current file (if any) size in bytes.
    double size();
//
//  open_txt_output(): To open the current file (if any) and to store its
//                     current fstream object in the given one. It will be
//                     open as plain text to write only.
    void open_txt_output(std::fstream &file);
//
//  open_txt_output(): To open the current file (if any) and to store its
//                     current fstream object in the given one. It will be
//                     open as plain text to read only.
    void open_txt_input(std::fstream &file);
//
//  open_bin_output(): To open the current file (if any) and to store its
//                     current fstream object in the given one. It will be
//                     open as binary to write only.
    void open_bin_output(std::fstream &file);
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
    #include "file_system__no_such_file.cpp"
    #include "file_system__no_such_path.cpp"
    #include "file_system__close.cpp"
    #include "file_system__is_open.cpp"
    #include "file_system__my_size.cpp"
};
#endif
