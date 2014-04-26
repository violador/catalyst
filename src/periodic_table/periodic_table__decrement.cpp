//
//
//
/// @brief Moves the current element back.
//
/// @return None.
//
inline void operator --()
{
//
/// @note Notice that the usage of this operator after or before the
///       current object, @c --object or @c object--, works exactly
///       the same way: Moves back the current element.
//
	switch(current_element > 1)
	{
		case true:
		--current_element;
		update_data();
		return;
	}
};
//
//
//
/// @brief Moves the current element back.
//
/// @return None.
//
inline void operator --(int)
{
//
/// @note Notice that the usage of this operator after or before the
///       current object, @c --object or @c object--, works exactly
///       the same way: Moves back the current element.
//
	switch(current_element > 1)
	{
		case true:
		--current_element;
		update_data();
		return;
	}
};
