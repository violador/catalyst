//
//
//
/// @brief A help function used to open the @c log_file stream.
//
/// @return None.
//
inline void open()
{
	manager.file_system::open_txt_output(log_file);
	switch(manager.file_system::is_open())
	{
		case true:
		log_file_ready = true;
		return;
	}
};
