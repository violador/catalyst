//
//
//
/// @brief Returns the size of the current object in bytes.
//
/// @return A non-negative real number.
//
inline double my_size()
{
//
/// @note Notice that the current size is almost the sum
///       of all the members. It is not exactly the size
///       of the object but it will never be less than
///       that.
//
    return sizeof(config_file) + sizeof(total_tasks)
	                           + sizeof(output_mode_on)
	                           + sizeof(vibration_mode_on)
	                           + sizeof(rotation_mode_on)
	                           + sizeof(translation_mode_on)
	                           + sizeof(debug_mode_on)
	                           + sizeof(highend_mode_on)
	                           + sizeof(standby_mode_on)
	                           + sizeof(temp_files_on)
	                           + sizeof(logging_matrices)
	                           + sizeof(precision)
	                           + sizeof(scf_criteria)
	                           + total_tasks*sizeof(input_list)
	                           + total_tasks*sizeof(level_list)
	                           + input_manager.file_system::my_size()
	                           + scratch_dir_manager.file_system::my_size()
	                           + work_dir_manager.file_system::my_size();
};
