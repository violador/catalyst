//
//
//
/// @param [in] a A real number, where @f$ 0.0 < a \leq 171.0 @f$.
//
/// @brief Calls the GSL library to calculate the value of the gamma function.
//
/// @return @f$ := \Gamma(a) \equiv (a - 1)! @f$. If @f$ a @f$ is out of range,
///         the function returns zero.
//
inline double gamma_function(const double &a)
{
	switch(a <= 0.0 || a > GSL_SF_GAMMA_XMAX)
	{
		case false: return gsl_sf_gamma(a); break;
		case  true: return 0.0; break;
	}
};
