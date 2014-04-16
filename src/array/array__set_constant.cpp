//
//
//
/// @brief Turns on the constant property,
///        if the current object is a not
///        deleted array.
//
/// @return None.
//
inline void set_constant()
{
	switch(not deleted_array)
	{
		case true:
		is_const_array = true;
		break;
	}
};
