//
//
//
/// @param [in] a An integer number, where @f$ 0 < a \leq 170 @f$.
//
/// @brief Calls the GSL library to calculate the factorial of the
///        given @c a.
//
/// @return @f$ a! @f$. If @f$ a @f$ is out of range, the function
///         returns one.
//
inline double factorial(const int &a)
{
	switch(a <= 0 or a > GSL_SF_FACT_NMAX)
	{
		case false: return gsl_sf_fact(a); break;
		case  true: return 1.0; break;
	}
};
