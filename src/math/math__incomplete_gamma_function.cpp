//
//
//
/// @param [in] a A real number.
//
/// @param [in] b A real number, where @f$ b \geq 0.0 @f$.
//
/// @brief Calls the GSL library to calculate the incomplete
///        gamma function.
//
/// @return @f[ \int_{b}^{\infty} t^{a - 1} \exp(-t)dt @f]
///         If @f$ b @f$ is out of range, the function
///         returns zero.
//
inline double incomplete_gamma_function(const double &a,
										const double &b)
{
	switch(b >= 0.0)
	{
		case false: return 0.0; break;
		case  true: return gsl_sf_gamma_inc(a, b); break;
	}
};
