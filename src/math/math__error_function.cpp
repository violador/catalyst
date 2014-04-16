//
//
//
/// @param [in] a A real number.
//
/// @brief Calls the GSL library to calculate the error function.
//
/// @return @f$ erf(a) @f$.
//
inline double error_function(const double &a)
{
	return gsl_sf_erf(a);
};
