//
//
//
/// @param [in] primitive The number of the primitive function.
//
/// @brief Returns the exponent value of the given primitive
///        function. Or returns zero, if the given primitive
///        functions number is out of the current set size.
//
/// @return A real number.
//
inline double &function_expon(const unsigned int &primitive)
{
	switch(primitive <= current_set_size)
	{
		case false: return expon[0]; break;
		case  true: return expon[primitive]; break;
	}
};
//
//
//
/// @brief Returns the exponent value of the primitive function
///        given by the internal iterator.
//
/// @return A real number.
//
inline double &function_expon()
{
	return expon[iter];
};
