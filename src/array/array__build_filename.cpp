//
//
//
/// @brief A private help function that uses the current
///        array ID to build a filename used to store its
///        content in the disk (and other applications).
//
/// @return None.
//
inline std::string build_filename()
{
	int id = tools::random_number<int>(time(NULL)*rank1);
	return "array" + tools::convert<std::string>(id) + ".bin";
};
