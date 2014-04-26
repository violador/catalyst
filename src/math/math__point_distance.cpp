//
//
//
/// @param [in] x1 A numerical (only) argument: the x-axis value of the first point.
//
/// @param [in] x2 A numerical (only) argument: the x-axis value of the second point.
//
/// @brief Calculates the distance between two points onto only one axis.
//
/// @return @f$ := |x_{2} - x_{1}| @f$
//
template<typename data_type>
inline data_type point_distance(const data_type &x1,
                                const data_type &x2)
{
	return module(x2, x1);
};
//
//
//
/// @param [in] x1 A numerical (only) argument: the x-axis value of the first point.
//
/// @param [in] y1 A numerical (only) argument: the y-axis value of the first point.
//
/// @param [in] x2 A numerical (only) argument: the x-axis value of the second point.
//
/// @param [in] y2 A numerical (only) argument: the y-axis value of the second point.
//
/// @brief Calculates the distance between two points by means of their set
///        of coordinates onto two axis.
//
/// @return @f$ := \sqrt{(x_{2} - x_{1})^{2} + (y_{2} - y_{1})^{2}} @f$
//
template<typename data_type>
inline data_type point_distance(const data_type &x1,
                                const data_type &y1,
                                const data_type &x2,
                                const data_type &y2)
{
	return std::sqrt(gsl_pow_2(x2 - x1) + gsl_pow_2(y2 - y1));
};
//
//
//
/// @param [in] x1 A numerical (only) argument: the x-axis value of the first point.
//
/// @param [in] y1 A numerical (only) argument: the y-axis value of the first point.
//
/// @param [in] z1 A numerical (only) argument: the z-axis value of the first point.
//
/// @param [in] x2 A numerical (only) argument: the x-axis value of the second point.
//
/// @param [in] y2 A numerical (only) argument: the y-axis value of the second point.
//
/// @param [in] z2 A numerical (only) argument: the z-axis value of the second point.
//
/// @brief Calculates the distance between two points by means of their set
///        of coordinates onto three axis.
//
/// @return @f$ := \sqrt{(x_{2} - x_{1})^{2} + (y_{2} - y_{1})^{2} + (z_{2} - z_{1})^{2}} @f$
//
template<typename data_type>
inline data_type point_distance(const data_type &x1,
                                const data_type &y1,
                                const data_type &z1,
                                const data_type &x2,
                                const data_type &y2,
                                const data_type &z2)
{
	return std::sqrt(gsl_pow_2(x2 - x1) + gsl_pow_2(y2 - y1) + gsl_pow_2(z2 - z1));
};
