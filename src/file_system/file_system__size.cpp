//
//
//
/// @brief Returns the file size in bytes if the file exists.
//
/// @return A non-negative real number. Or returns zero if the
///         file do not exist.
//
inline double size()
{
	switch(exists())
	{
		case false: return 0.0; break;
		case  true: return boost::filesystem::file_size(file); break;
	}
};
