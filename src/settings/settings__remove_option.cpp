//
//
//
/// @brief A help function that changes a given @c line from the config file,
///        removing the @c option part. What remains should be the key. The
///        pattern used is @c "option = key".
//
/// @return None.
//
inline void remove_option(std::string &line,
						  const std::string &option)
{
//
/// @warning The content of the given @c line will be modified.
//
	line.std::string::erase(0, tools::pattern_length(option));
};
