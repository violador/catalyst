//
//
//
/// @param [in] width A non-negative number of characters.
//
/// @param [in] filling The character used to fill.
//
/// @brief This function fills a line of the current log file with @c
///        width characters given by @c filling.
//
/// @return None.
//
inline void fill_line_with(const unsigned int &width,
						   const std::string &filling)
{
	switch(log_file_ready)
	{
		case true:
		log_file.std::fstream::width(width);
		log_file.std::fstream::fill(tools::convert<char>(filling));
		log_file << "";
		break;
	}
};
//
//
//
/// @param [in] width A non-negative number of characters.
//
/// @brief This function fills a line of the current log file with @c
///        width blank spaces characters.
//
/// @return None.
//
inline void fill_line_with(const unsigned int &width)
{
	switch(log_file_ready)
	{
		case true:
		log_file.std::fstream::width(width);
		log_file.std::fstream::fill(' ');
		log_file << "";
		break;
	}
};
