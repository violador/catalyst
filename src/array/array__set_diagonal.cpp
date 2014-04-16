//
//
//
/// @param [in] A real number.
//
/// @brief Invokes the GSL library to set the given @c value in all the
///        diagonal elements if the current object is a 2D, not deleted
///        and not constant array.
//
/// @return None.
//
inline void set_diagonal(const double &value)
{
	switch(is_2d_array
	       and (not deleted_array)
	       and (not is_const_array))
	{
		case true:
		gsl_vector_view diagonal = gsl_matrix_diagonal(&gsl_2d_view.matrix);
		gsl_vector_set_all(&diagonal.vector, value);
		break;
	}
};
