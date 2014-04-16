//
//
//
/// @brief Checks the current total disk space in gigabyte based
///        on the current path.
//
/// @return A non-negative real number.
//
inline double check_disk_capacity()
{
	return disk_space.boost::filesystem::space_info::capacity
			*tools::byte_to_gigabyte();
};
