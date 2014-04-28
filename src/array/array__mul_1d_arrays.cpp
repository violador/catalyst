//
//
//
/// @param [out] A An 1D and not constant array.
//
/// @param [in] b A real number.
//
/// @brief A help function to scale the given @c A array by the
///        given factor @c b, using the CBLAS library.
//
/// @return None.
//
inline void mul_1d_arrays(array &A, const double &b)
{
	cblas_dscal(A.rank1, b, A.data1, 1);
};
