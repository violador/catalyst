//
//
//
/// @param [in] task The number of a given task
//
/// @brief Returns the current level of theory (its enum) for a
///        given task.
//
/// @return A non-negative integer.
//
inline unsigned int &task_level(unsigned int &task)
{
	switch(task <= total_tasks)
	{
		case false: return level_list[0]; break;
		case  true: return level_list[task - 1]; break;
	}
};
