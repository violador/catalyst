//
//
//
/// @param [in] value A real number.
//
/// @brief A help function used to set up the given value into all the
///        elements if the current object is not a deleted or constant
///        1D array.
//
/// @return None.
//
inline void set_all_1d_elements(const double &value)
{
	switch(is_1d() && is_okay())
	{
		case true:
		gsl_vector_set_all(&gsl_1d_view.vector, value);
		return;
	}
};
