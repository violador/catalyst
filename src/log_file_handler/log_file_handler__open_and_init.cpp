//
//
//
/// @brief A help function used in the constructor that open and
///        initializes the log file if the file do not exists yet.
//
/// @return None.
//
void inline open_and_init()
{
	manager.file_system::open_txt_output(log_file);
	switch(manager.file_system::is_open())
	{
		case false:
		{
			report_bad_init();
		}
		break;
		case true:
		{
			log_file_ready = true;
			init_log_file();
			report_input_list();
		}
		break;
	}
};
