//
//
//
/// @param [in] value A real number.
//
/// @brief A help function used to set up the given value into all the
///        elements if the current object is not a deleted or constant
///        2D array.
//
/// @return None.
//
inline void set_all_2d_elements(const double &value)
{
	switch(is_2d() && is_okay())
	{
		case true:
		gsl_matrix_set_all(&gsl_2d_view.matrix, value);
		return;
	}
};
