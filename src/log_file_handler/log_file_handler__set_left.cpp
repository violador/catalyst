//
//
//
/// @brief Sets any further data printed in
///        the log file at left hand side.
//
/// @return None.
//
inline void set_left()
{
	switch(log_file_ready)
	{
		case  true:
		log_file.std::fstream::fill(' ');
		log_file << std::left;
		break;
	}
};
