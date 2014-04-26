//
//
//
/// @param [in] a An integer number, where @f$ 0 < a \leq 297 @f$.
//
/// @brief Calls the GSL library to compute the double factorial of
///        the given @c a.
//
/// @return @f$ a!! @f$. If @f$ a @f$ is out of range, the function
///         returns one.
//
inline double double_factorial(const int &a)
{
	switch(a <= 0 || a > GSL_SF_DOUBLEFACT_NMAX)
	{
		case false: return gsl_sf_doublefact(a); break;
		case  true: return 1.0; break;
	}
};
