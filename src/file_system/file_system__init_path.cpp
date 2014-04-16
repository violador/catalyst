//
//
//
/// @param [in] given_pathname A string pattern with the desired path.
//
/// @brief A help function used to initialize the current path.
//
/// @return A @c boost::filesystem::path pointer.
//
inline boost::filesystem::path* init_path(const std::string &given_pathname)
{
	switch(given_pathname.std::string::empty())
	{
		case false:
		{
			boost::filesystem::path init(given_pathname);
			path = init;
			return &path;
		}
		break;
		case true:
		{
//
/// 			@note Notice that if the @c given_pathname is an empty string, the function
///                           uses the default directory defined in the tools::default_current_dir().
//
			boost::filesystem::path init(tools::default_current_dir());
			path = init;
			return &path;
		}
		break;
	}
	return NULL;
};
//
//
//
/// @brief A help function used to initialize the default path, defined
///        in the tools::default_current_dir(), as the current path.
//
/// @return A @c boost::filesystem::path pointer.
//
inline boost::filesystem::path* init_path()
{
	boost::filesystem::path init(tools::default_current_dir());
	path = init;
	return &path;
};
