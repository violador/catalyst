//
//
//
/// @param [in] task The number of a given task
//
/// @brief Returns the input filename of the given @c task.
//
/// @return A string pattern.
//
inline std::string input_filename(const unsigned int &task)
{
	switch(task <= total_tasks)
	{
		case true:
		input_manager.file_system::init(work_dir(), input_list[task - 1]);
		switch(input_manager.file_system::exists()
		       && input_manager.file_system::is_file())
		{
			case true:
			return input_manager.file_system::full_name();
		}
	}
	return "";
};
