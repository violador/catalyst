//
//
//
/// @brief Returns the atomic number, @f$ Z @f$, of the current element.
//
/// @return A real number.
//
inline double atomic_number()
{
	return tools::convert<double>(current_element);
};
