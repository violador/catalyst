//
//
//
/// @param [in] i The element position.
//
/// @param [in] value The new element value.
//
/// @brief Sets a new value in the given element position
///        if the current object is an 1D, not deleted and
///        not constant array. If @c i is out of range,
///        nothing is done.
//
/// @return None.
//
inline void set(const unsigned int &i,
				const double &value)
{
	switch(is_1d_array
			and (not deleted_array)
			and (not is_const_array)
			and (i <= sizeof_row))
	{
		case true:
		user_1d_array[i - 1] = value;
		break;
	}
};
//
//
//
/// @param [in] i The element position.
//
/// @param [in] j The element position.
//
/// @param [in] value The new element value.
//
/// @brief Sets a new value in the given element position
///        if the current object is a 2D, not deleted and
///        not constant array. If @c i or @c j is out of
///        range, nothing is done.
//
/// @return None.
//
inline void set(const unsigned int &i,
				const unsigned int &j,
				const double &value)
{
	switch(is_2d_array
		   and (not deleted_array)
		   and (not is_const_array)
		   and (i <= sizeof_row)
		   and (j <= sizeof_column))
	{
		case true:
		user_2d_array[(i - 1)*sizeof_row + (j - 1)] = value;
		break;
	}
};
//
//
//
/// @param [in] i The element position.
//
/// @param [in] j The element position.
//
/// @param [in] m The element position.
//
/// @param [in] value The new element value.
//
/// @brief Sets a new value in the given element position
///        if the current object is a 3D, not deleted and
///        not constant array. If @c i, @c j or @c m is
///        out of range, nothing is done.
//
/// @return None.
//
inline void set(const unsigned int &i,
				const unsigned int &j,
				const unsigned int &m,
				const double &value)
{
	switch(is_3d_array
			and (not deleted_array)
			and (not is_const_array)
			and (i <= sizeof_row)
			and (j <= sizeof_column)
			and (m <= sizeof_1st_layer))
	{
		case true:
		user_3d_array[i - 1][j - 1][m - 1] = value;
		break;
	}
};
//
//
//
/// @param [in] i The element position.
//
/// @param [in] j The element position.
//
/// @param [in] m The element position.
//
/// @param [in] n The element position.
//
/// @param [in] value The new element value.
//
/// @brief Sets a new value in the given element position
///        if the current object is a 4D, not deleted and
///        not constant array. If @c i, @c j, @c m or @c
///        n is out of range, nothing is done.
//
/// @return None.
//
inline void set(const unsigned int &i,
				const unsigned int &j,
				const unsigned int &m,
				const unsigned int &n,
				const double &value)
{
	switch(is_4d_array
			and (not deleted_array)
			and (not is_const_array)
			and (i <= sizeof_1st_layer)
			and (j <= sizeof_2nd_layer)
			and (m <= sizeof_row)
			and (n <= sizeof_column))
	{
		case true:
		user_4d_array[i - 1][j - 1][m - 1][n - 1] = value;
		break;
	}
};
