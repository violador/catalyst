//
//
//
/// @brief Moves the current iterator forward.
//
/// @return None.
//
inline void operator ++()
{
//
/// @note Notice that the usage of this operator after or before the
///       current object, @c ++object or @c object++, works exactly
///       the same way: Moves forward the current element.
//
	switch(iter < current_set_size)
	{
		case true: ++iter; break;
	}
};
//
//
//
/// @brief Increments the internal iterator.
//
/// @return None.
//
inline void operator ++(int)
{
//
/// @note Notice that the usage of this operator after or before the
///       current object, @c ++object or @c object++, works exactly
///       the same way: Moves forward the current element.
//
	switch(iter < current_set_size)
	{
		case true: ++iter; break;
	}
};
