//
//
//
/// @param [in] a A numerical (only) argument.
//
/// @brief Calculates the absolute value of the given @f$ a @f$.
//
/// @return @f$ := |a| @f$
//
template<typename data_type>
inline data_type module(const data_type &a)
{
	switch(a >= 0.0)
	{
		case false: return -a; break;
		case  true: return  a; break;
	}
};
//
//
//
/// @param [in] a A numerical (only) argument.
//
/// @param [in] b A numerical (only) argument.
//
/// @brief Calculates the absolute value of the difference between the
///        given @f$ a @f$ and @f$ b @f$.
//
/// @return @f$ := |a - b| @f$
//
template<typename data_type>
inline data_type module(const data_type &a,
                        const data_type &b)
{
	return module(a - b);
};
