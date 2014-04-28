//
//
//
/// @param [out] output A 2D and not constant array object.
//
/// @brief Copies the transposed elements of the current
///        object to the @c output one. If the size of the
///        @c output do not fits, it will be redimensioned.
//
/// @return None.
//
inline void save_transpose_to(array &output)
{
	switch(this -> is_2d()
			and output.is_2d()
			and (not output.constant))
	{
		case true:
		output.resize(this -> rank1, this -> rank2);
//
/// 	@notice Notice that the content of @c output is going to be modified.
		gsl_matrix_transpose_memcpy(&output.gsl_2d_view.matrix,
									&this -> gsl_2d_view.matrix);
		break;
	}
};
