//
//
//
/// @brief Returns the conversion factor from bytes to gigabytes.
//
/// @return @f$ 0.000000000931322575 @f$
//
inline const double GB()
{
	return 0.000000000931322575;
};
//
//
//
/// @param [in] data_size A numerical (only) argument in byte units.
//
/// @brief Converts the given @c data_size to gigabyte units.
//
/// @return @f$ := \times 0.000000000931322575 @f$
//
template<typename data_type>
inline double GB(const data_type &data_size)
{
	return data_size*0.000000000931322575;
};
