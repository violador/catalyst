//
//
//
/// @brief Calls the CBLAS library to calculate the euclidean norm of the array,
///        if it is an 1D and not deleted object.
//
/// @return @f$ \sqrt{A^{2}_{1} + \ldots + A^{2}_{n}} @f$, where @f$ n := @f$ @c
///         rank1.
//
inline double norm()
{
	switch(is_1d() && not_deleted())
	{
		case false: return 0.0;
		case  true: return cblas_dnrm2(rank1, data1, 1);
	}
};
