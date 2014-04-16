//
//
//
/// @param [in] given_pathname A string pattern with the desired path.
//
/// @param [in] given_filename A string pattern with the desired file.
//
/// @brief A help function used to initialize the current file.
//
/// @return A @c boost::filesystem::path pointer.
//
inline boost::filesystem::path* init_file(const std::string &given_filename,
										  const std::string &given_pathname)
{
	switch(given_pathname.std::string::empty())
	{
		case false:
		{
			boost::filesystem::path init(given_pathname + given_filename);
			file = init;
			return &file;
		}
		break;
		case true:
		{
//
/// 			@note Notice that if the @c given_pathname is an empty string, the function
///                           uses the default directory defined in the tools::default_current_dir().
//
			boost::filesystem::path init(tools::default_current_dir() + given_filename);
			file = init;
			return &file;
		}
		break;
	}
	return NULL;
};
//
//
//
/// @brief A help function used to initialize the file with the default path,
///        defined in the tools::default_current_dir(), as the current path.
//
/// @return A @c boost::filesystem::path pointer.
//
inline boost::filesystem::path* init_file(const std::string &given_filename)
{
	boost::filesystem::path init(tools::default_current_dir() + given_filename);
	file = init;
	return &file;
};
//
//
//
/// @brief A help function used to initialize no file in the default path,
///        defined in the tools::default_current_dir(), as the current path.
//
/// @return A @c boost::filesystem::path pointer.
//
inline boost::filesystem::path* init_file()
{
	boost::filesystem::path init(tools::default_current_dir());
	file = init;
	return &file;
};
