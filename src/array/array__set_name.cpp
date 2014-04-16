//
//
//
/// @brief Sets a name for the current array object,
///        if not deleted.
//
/// @return None.
//
inline void set_name(const std::string &given_name)
{
	switch(not deleted_array)
	{
		case true: array_name = given_name; break;
	}
};
