//
//
//
/// @param [out] A An 1D and non-constant array.
//
/// @param [in] b A real number.
//
/// @brief A private help function to add the factor @c b to all
///        the elements of the given @c A array, using the GSL
///        library.
//
/// @return None.
//
inline void add_1d_arrays(array &A, const double &b)
{
	gsl_vector_add_constant(&A.gsl_1d_view.vector, b);
};
//
//
//
/// @param [out] A An 1D and non-constant array.
//
/// @param [in] B An 1D array.
//
/// @brief A private help function to add the given array @c B to
///        the given array @c A if they are both 1D type and its
///        dimension sizes fits, using the CBLAS library.
//
/// @return None.
//
inline void add_1d_arrays(array &A, const array &B)
{
	switch(A.rank1 == B.rank1)
	{
		case true:
		cblas_daxpy(A.rank1,
		            1.0,
		            B.data1,
		            1,
		            A.data1,
		            1);
		return;
	}
};
