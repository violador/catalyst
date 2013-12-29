//
//
//
template<typename data_type>
inline data_type point_distance(const data_type &a, // x-axis value of the first point.
                                const data_type &b) // x-axis value of the second point.
{
    return module(a, b);
};
//
//
//
template<typename data_type>
inline data_type point_distance(const data_type &a, // x-axis value of the first point.
                                const data_type &b, // y-axis value of the first point.
                                const data_type &c, // x-axis value of the second point.
                                const data_type &d) // y-axis value of the second point.
{
    return std::sqrt(gsl_pow_2(c - a) + gsl_pow_2(d - b));
};
//
//
//
template<typename data_type>
inline data_type point_distance(const data_type &a, // x-axis value of the first point.
                                const data_type &b, // y-axis value of the first point.
                                const data_type &c, // z-axis value of the first point.
                                const data_type &d, // x-axis value of the second point.
                                const data_type &e, // y-axis value of the second point.
                                const data_type &f) // z-axis value of the second point.
{
    return std::sqrt(gsl_pow_2(d - a) + gsl_pow_2(e - b) + gsl_pow_2(f - c));
};
