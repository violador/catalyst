//
//
//
/// @brief Turns off the constant property, if previously
///        turned on.
//
/// @return None.
//
inline void unset_constant()
{
	switch(not deleted_array and is_const_array)
	{
		case true: is_const_array = false; break;
	}
};
