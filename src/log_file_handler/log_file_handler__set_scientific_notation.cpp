//
//
//
/// @param [in] width The number of characters to print any numeric data
///                   (centered at right hand side).
//
/// @brief Changes the numeric notation used in the log file to scientific
///        with precision defined in the current @c config pointer.
//
/// @return None.
//
inline void set_scientific_notation(const unsigned int &width)
{
	switch(log_file_ready)
	{
		case true:
		log_file << std::scientific;
		log_file.std::fstream::width(width);
		log_file.std::fstream::precision(config -> numeric_precision());
		log_file << std::right;
		break;
	}
};
//
//
//
/// @brief Changes the numeric notation used in the log file to scientific
///        with precision defined in the current @c config pointer.
//
/// @return None.
//
inline void set_scientific_notation()
{
	switch(log_file_ready)
	{
		case true:
		log_file << std::scientific;
		log_file.std::fstream::width(MAX_PRECISION + SPACE_LENGTH);
		log_file.std::fstream::precision(config -> numeric_precision());
		log_file << std::right;
		break;
	}
};
