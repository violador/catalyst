//
//
//
/// @brief Checks the current disk space in gigabyte based on the current path.
//
/// @return A non-negative real number.
//
inline double check_disk_space()
{
	return tools::GB(disk_space.boost::filesystem::space_info::available);
};
