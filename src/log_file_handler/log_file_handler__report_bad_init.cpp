//
//
//
inline void report_bad_init()
{
    std::cout << "\n@Catalyst: fails to create "
              << config -> filename_of(option::log_file)
              << " in the folder "
              << file_manager -> parent_dir()
              << ". The program will keep running without write the file."
              << " You may or may not see the output properly." << std::endl;
};
