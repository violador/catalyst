//
//
//
/// @brief A help function used to close the current log file.
//
/// @return None.
//
inline void close()
{
	switch(log_file_ready)
	{
		case true:
		manager.file_system::close(log_file);
		log_file_ready = false;
		break;
	}
};
