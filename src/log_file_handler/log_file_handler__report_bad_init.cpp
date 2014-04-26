//
//
//
/// @brief A help function used in the constructor to print a warning
///        in the standard output of errors when the log file was not
///        opened for some reason.
//
/// @return None.
//
inline void report_bad_init()
{
//
/// @note Notice that this function prints a warning in the standard
///       output of errors (usually the screen) but is not redirected
///       for an outside file by pipes. Also notice that the program
///       keeps running if this message is printed (meaning that the
///       log file is not opened).
//
	std::cerr << "\n@Catalyst: fails to create "
	          << manager.file_system::name()
	          << " in the folder <"
	          << manager.file_system::parent_dir()
	          << ">. The program will keep running without write the file."
	          << " You may or may not see the output properly." << std::endl;
};
