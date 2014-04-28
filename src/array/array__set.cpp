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
	switch(is_1d()
			and (not is_deleted())
			and (not constant)
			and (i <= rank1))
	{
		case true:
		data1[i - 1] = value;
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
	switch(is_2d()
		   and (not is_deleted())
		   and (not constant)
		   and (i <= rank1)
		   and (j <= rank2))
	{
		case true:
		data2[(i - 1)*rank1 + (j - 1)] = value;
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
	switch(is_3d()
			and (not is_deleted())
			and (not constant)
			and (i <= rank1)
			and (j <= rank2)
			and (m <= rank3))
	{
		case true:
		data3[i - 1][j - 1][m - 1] = value;
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
	switch(is_4d()
			and (not is_deleted())
			and (not constant)
			and (i <= rank3)
			and (j <= rank4)
			and (m <= rank1)
			and (n <= rank2))
	{
		case true:
		data4[i - 1][j - 1][m - 1][n - 1] = value;
		break;
	}
};
