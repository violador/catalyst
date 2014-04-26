//
//
//
inline void copy_2d_arrays(const array &B)
{
	resize(B.sizeof_row, B.sizeof_column);
	gsl_matrix_memcpy(&this -> gsl_2d_view.matrix, &B.gsl_2d_view.matrix);
};
