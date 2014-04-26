//
//
//
/// @brief The factor for conversions from bytes to kilobytes.
//
/// @return @f$ 0.0009765625 @f$
//
inline const double kB()
{
	return 0.0009765625;
};
//
//
//
/// @param [in] data_size A numerical (only) argument in byte units.
//
/// @brief Converts the given @c data_size to kilobyte units.
//
/// @return @f$ := \times 0.0009765625 @f$
//
template<typename data_type>
inline double kB(const data_type &data_size)
{
	return data_size*0.0009765625;
};
