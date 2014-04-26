//
//
//
/// @param [in] width The number of characters.
//
/// @brief Sets the size used to print any numerical data in
///        the current log file.
//
/// @return None.
//
inline void set_width(const unsigned int &width)
{
	switch(log_file_ready)
	{
		case true:
		log_file.std::fstream::width(width);
		return;
	}
};
