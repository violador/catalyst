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
	switch(not is_deleted())
	{
		case true:
		constant = true;
		break;
	}
};
