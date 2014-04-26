//
//
//
/// @brief Calls the CBLAS library to calculate the euclidean norm of the array,
///        if it is an 1D and not deleted object.
//
/// @return @f$ \sqrt{A^{2}_{1} + \ldots + A^{2}_{n}} @f$, where @f$ n := @f$ @c
///         sizeof_row.
//
inline double norm()
{
	switch(is_1d() && (!is_deleted()))
	{
		case true:
		return cblas_dnrm2(sizeof_row, user_1d_array, 1);
	}
	return 0.0;
};
