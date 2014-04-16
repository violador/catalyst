//
//
//
/// @brief Works only on 2D, not deleted and non-constant
///        arrays invoking the GSL library to build its
///        identity form, where @f$ A_{i = j} = 1 @f$ and
///        @f$ A_{i \neq j} = 0 @f$.
//
/// @return None.
//
inline void build_identity_form()
{
//
/// @warning @modification_warn
//
	switch(is_2d_array
	       && (!is_deleted())
	       && (!is_const_array))
	{
		case true:
		gsl_matrix_set_identity(&gsl_2d_view.matrix);
		break;
	}
};
