//
//
//
/// @param [in] a A numerical (only) argument.
//
/// @param [in] b A numerical (only) argument.
//
/// @brief Calculates the square of the absolute value of the difference
///        between the given @f$ a @f$ and @f$ b @f$.
//
/// @return @f$ := |a - b|^{2} @f$
//
template<typename data_type>
inline data_type square_module(const data_type &a,
                               const data_type &b)
{
	return std::pow(module(a - b), 2.0);
};
