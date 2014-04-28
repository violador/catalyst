//
//
//
/// @brief Returns the current value in the @f$ A_{i} @f$ element.
//
/// @return A @c double type number.
//
inline double &operator ()(const unsigned int &i) const
{
//
/// @warning This function do not checks the array bounds.
///          If the given element is out of range, it
///          throws the standard C/C++ out of range error.
//
	return data1[i - 1];
};
//
//
//
/// @brief Sets the given @c value in the @f$ A_{i} @f$ element
///        if the current object is a non-constant array.
//
/// @return None.
//
inline void operator ()(const unsigned int &i,
                        const double &value)
{
//
/// @warning This function do not checks the array bounds.
///          If the given element is out of range, it
///          throws the standard C/C++ out of range error.
//
	switch(is_okay())
	{
		case true:
		data1[i - 1] = value;
		return;
	}
};
//
//
//
/// @brief Returns the current @c value in the @f$ A_{i, j} @f$
///        element.
//
/// @return A @c double type number.
//
inline double &operator ()(const unsigned int &i,
                           const unsigned int &j) const
{
//
/// @warning This function do not checks the array bounds.
///          If the given element is out of range, it
///          throws the standard C/C++ out of range error.
//
	return data2[(i - 1)*rank1 + (j - 1)];
};
//
//
//
/// @brief Sets the given @c value in the @f$ A_{i, j} @f$ element
///        if the current object is a non-constant array.
//
/// @return None.
//
inline void operator ()(const unsigned int &i,
                        const unsigned int &j,
                        const double &value)
{
//
/// @warning This function do not checks the array bounds.
///          If the given element is out of range, it
///          throws the standard C/C++ out of range error.
//
	switch(is_okay())
	{
		case true:
		data2[(i - 1)*rank1 + (j - 1)] = value;
		return;
	}
};
//
//
//
/// @brief Returns the current value in the @f$ A_{i, j, m} @f$
///        element.
//
/// @return A @c double type number.
//
inline double &operator ()(const unsigned int &i,
                           const unsigned int &j,
                           const unsigned int &m) const
{
//
/// @warning This function do not checks the array bounds.
///          If the given element is out of range, it
///          throws the standard C/C++ out of range error.
//
	return data3[i - 1][j - 1][m - 1];
};
//
//
//
/// @brief Sets the given @c value in the @f$ A_{i, j, m}
///        @f$ element if the current object is a
///        non-constant array.
//
/// @return None.
//
inline void operator ()(const unsigned int &i,
                        const unsigned int &j,
                        const unsigned int &m,
                        const double &value)
{
//
/// @warning This function do not checks the array bounds.
///          If the given element is out of range, it
///          throws the standard C/C++ out of range error.
//
	switch(is_okay())
	{
		case true:
		data3[i - 1][j - 1][m - 1] = value;
		return;
	}
};
//
//
//
/// @brief Returns the current value in the @f$ A_{i, j, m, n}
///        @f$ element.
//
/// @return A @c double type number.
//
inline double &operator ()(const unsigned int &i,
                           const unsigned int &j,
                           const unsigned int &m,
                           const unsigned int &n) const
{
//
/// @warning This function do not checks the array bounds.
///          If the given element is out of range, it
///          throws the standard C/C++ out of range error.
//
	return data4[i - 1][j - 1][m - 1][n - 1];
};
//
//
//
/// @brief Sets the given @c value in the @f$ A_{i, j, m, n}
///        @f$ element if the current object is a non-constant
///        array.
//
/// @return None.
//
inline void operator ()(const unsigned int &i,
                        const unsigned int &j,
                        const unsigned int &m,
                        const unsigned int &n,
                        const double &value)
{
//
/// @warning This function do not checks the array bounds.
///          If the given element is out of range, it
///          throws the standard C/C++ out of range error.
//
	switch(is_okay())
	{
		case true:
		data4[i - 1][j - 1][m - 1][n - 1] = value;
		return;
	}
};
