//
//
//
/// @brief Returns the conversion factor from bytes to megabytes.
//
/// @return @f$ 0.000000954 @f$
//
inline const double MB()
{
	return 0.000000954;
};
//
//
//
/// @param [in] data_size A numerical (only) argument in byte units.
//
/// @brief Converts the given @c data_size to megabyte units.
//
/// @return @f$ := \times 0.000000954 @f$
//
template<typename data_type>
inline double MB(const data_type &data_size)
{
	return data_size*0.000000954;
};
