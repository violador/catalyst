//
//
//
/// @param [in] a A templated number.
//
/// @param [in] b A templated number.
//
/// @brief Calculates the Kronecker's delta, @f$ \delta_{a, b} @f$.
//
/// @return One if @f$ a = b @f$, and zero otherwise.
//
template<typename data_type>
inline data_type kronecker_delta(const data_type &a,
								 const data_type &b)
{
//
/// @warning The type of @c a and @c b must be the same. Otherwise it's
///          behavior is unknown. Also, by its templated nature, this
///          function accepts @c char and @c std::string types. But it
///          is meaningless too, thus, make sure to use only numerical
///          datas as input arguments.
//
	switch(a == b)
	{
		case false: return 0.0; break;
		case  true: return 1.0; break;
	}
};
