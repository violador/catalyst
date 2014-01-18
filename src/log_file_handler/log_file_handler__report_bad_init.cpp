//
//
//
inline void report_bad_init()
{
    std::cerr << "\n@Catalyst: fails to create "
              << manager.file_system::name()
              << " in the folder "
              << manager.file_system::parent_dir()
              << ". The program will keep running without write the file."
              << " You may or may not see the output properly." << std::endl;
};
