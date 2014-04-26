//
//
//
/// @param [in] b A real number.
//
//  @param [out] A A 2D and non-constant array.
//
/// @brief A private help function to add the factor @c b to all
///        the elements of the given @c A array, using the GSL
///        library.
//
/// @return None.
//
inline void add_2d_arrays(array &A, const double &b)
{
	gsl_matrix_add_constant(&A.gsl_2d_view.matrix, b);
};
//
//
//
/// @param [in] B A 2D array.
//
/// @param [out] A A 2D array and non-constant array.
//
/// @brief A private help function to add the given array @c B to
///        the given @c A if they are both 2D type and its dimension
///        sizes fits, using the CBLAS library.
//
inline void add_2d_arrays(array &A, const array &B)
{
	switch(A.sizeof_row == B.sizeof_row
	       && A.sizeof_column == B.sizeof_column)
	{
		case true:
		cblas_daxpy(A.sizeof_row*A.sizeof_column,
		            1.0,
		            B.user_2d_array,
		            1,
		            A.user_2d_array,
		            1);
		break;
	}
};
