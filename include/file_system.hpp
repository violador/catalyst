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
//  extension(): To return the current file extension, if any.
    #include "file_system__extension.cpp"
//
//  full_name(): To return the current full name (full path + filename, if any).
    #include "file_system__full_name.cpp"
//
//  name(): To return the current filename (name + extension, if any).
    #include "file_system__name.cpp"
//
//  is_dir(): To return the directory state (true if there is no file, just a directory path).
    #include "file_system__is_dir.cpp"
//
//  is_file(): To return the file state (true if the path ends in a filename).
    #include "file_system__is_file.cpp"
//
//  exists(): To return true if the current path (path + file, if any) exists.
    #include "file_system__exists.cpp"
//
//  size(): To return the size in bytes of the current file (if any).
    double size();
//
//  root_dir(): To return the current root directory.
    #include "file_system__root_dir.cpp"
//
//  parent_dir(): To return the current parent directory.
    #include "file_system__parent_dir.cpp"
//
//  relative_dir(): To return the current relative directory.
    #include "file_system__relative_dir.cpp"
//
//  no_such_file(): To return true if there is no file.
    #include "file_system__no_such_file.cpp"
//
//  no_such_path(): To return true if there is no path.
    #include "file_system__no_such_path.cpp"
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
//
    #include "file_system__close.cpp"
//
//  is_open(): To return true if the current fstream object was created 
//             properly.
    #include "file_system__is_open.cpp"
};
#endif
