//
//
//
/// @brief Returns the current disk/partition space in gigabytes.
///        The value is from the disk/partition that contains the
///        current scratch directory.
//
/// @return A non-negative real number.
//
inline double check_current_disk_space()
{
	return scratch_dir_manager.file_system::check_disk_space();
};
