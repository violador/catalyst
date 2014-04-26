//
//
//
/// @brief Changes the numeric notation used in the log file to fixed with
///        precision defined in the current @c config pointer.
//
/// @return None.
//
inline void set_fixed()
{
	switch(log_file_ready)
	{
		case true:
		log_file.std::fstream::precision(config -> numeric_precision());
		log_file << std::fixed;
		return;
	}
};
