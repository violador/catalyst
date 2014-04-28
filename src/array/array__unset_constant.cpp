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
	switch(not is_deleted() and constant)
	{
		case true: constant = false; break;
	}
};
