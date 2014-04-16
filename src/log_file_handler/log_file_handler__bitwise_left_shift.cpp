//
//
//
/// @param [in] output A templated data (either a number or a
///                    string pattern)
//
/// @brief This operator is used to print the given @c output
///        into the current log file.
//
/// @return None.
//
template<typename data_type>
inline void operator <<(const data_type &output)
{
	switch(config -> output_mode() and log_file_ready)
	{
		case true: log_file << output; break;
	}
};
