//
//
//
/// @brief Calls the CBLAS library to calculate the euclidean norm of the array.
///        Valid for rank one arrays only.
//
/// @return @f$ \sqrt{A^{2}_{1} + \ldots + A^{2}_{n}} @f$, where @f$ n := @f$ @c
///         array::first_rank().
//
inline double norm()
{
	switch(data != NULL)
	{
		case false: return 0.0;
		case  true: return cblas_dnrm2(rank1, data, 1);
	}
};
