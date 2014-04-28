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
	switch(not is_deleted())
	{
		case true: name = given_name; break;
	}
};
