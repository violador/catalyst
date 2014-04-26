//
//
//
/// @brief Checks the current partition/total disk space in gigabyte based
///        on the current path.
//
/// @return A non-negative real number.
//
inline double check_disk_capacity()
{
	return tools::GB(disk_space.boost::filesystem::space_info::capacity);
};
