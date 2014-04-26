//
//
//
/// @brief Sets a new line in the current log file.
//
/// @return None.
//
inline void set_new_line()
{
	switch(log_file_ready)
	{
		case true:
		log_file << std::endl;
		return;
	}
};
