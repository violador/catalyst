//
//
//
/// @brief Transpose the array, @f$ A_{i, j} = A_{j, i} @f$, if it is
///        a 2D square array, not constant and not deleted.
//
/// @return None.
//
inline void set_transpose()
{
	switch(is_2d_array
			and (not deleted_array)
			and (not is_const_array)
			and is_square_array)
	{
		case true:
		gsl_matrix_transpose(&gsl_2d_view.matrix);
		is_transposed? is_transposed = false : is_transposed = true;
		break;
	}
};
