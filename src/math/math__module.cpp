//
//
//
/// @param [in] a A templated number.
//
/// @brief Calculates the absolute value of the given @f$ a @f$.
//
/// @return @f$ |a| @f$
//
template<typename data_type>
inline data_type module(const data_type &a)
{
//
/// @warning By its templated nature, this function accepts @c char and
///          @c std::string types. But since it is meaningless make sure
///          to use only numerical datas as input arguments. Otherwise
///          its behavior may be unknown.
//
	switch(a >= 0.0)
	{
		case false: return -a; break;
		case  true: return  a; break;
	}
};
//
//
//
/// @param [in] a A templated number.
//
/// @param [in] b A templated number.
//
/// @brief Calculates the absolute value of the difference between the
///        given @f$ a @f$ and @f$ b @f$.
//
/// @return @f$ |a - b| @f$
//
template<typename data_type>
inline data_type module(const data_type &a,
						const data_type &b)
{
//
/// @warning By its templated nature, this function accepts @c char and
///          @c std::string types. But since it is meaningless make sure
///          to use only numerical datas as input arguments. Otherwise
///          its behavior may be unknown.
//
	return module(a - b);
};
