//
//
//
/// @param [in] a A templated number.
//
/// @param [in] b A templated number.
//
/// @brief Calculates the square of the absolute value of the difference
///        between the given @f$ a @f$ and @f$ b @f$.
//
/// @return @f$ |a - b|^{2} @f$
//
template<typename data_type>
inline data_type square_module(const data_type &a,
							   const data_type &b)
{
	return gsl_pow_2(module(a - b));
};
