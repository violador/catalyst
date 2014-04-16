//
//
//
/// @brief Checks if the current log file exists.
//
/// @return @c true if it exists, and @c false otherwise.
//
inline bool exists()
{
	return manager.file_system::exists();
};
