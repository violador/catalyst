//
//
//
/// @param [in] a A numerical (only) argument.
//
/// @param [in] b A numerical (only) argument.
//
/// @brief Calculates the Kronecker's delta, @f$ \delta_{a, b} @f$.
//
/// @return One if @f$ a = b @f$, and zero otherwise.
//
template<typename data_type>
inline data_type kronecker_delta(const data_type &a,
                                 const data_type &b)
{
	switch(a == b)
	{
		case false: return 0.0; break;
		case  true: return 1.0; break;
	}
};
