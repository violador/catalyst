//
//
//
/// @param [in] a A real number.
//
/// @brief Calls the GSL library to calculate
///        the exponential function of @c a.
//
/// @return @f$ := exp(a) @f$
//
inline double exp(const double &a)
{
	return gsl_sf_exp(a);
};
