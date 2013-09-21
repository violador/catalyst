//
//
//
template<typename data_type> data_type module(const data_type &a, const data_type &b)
{
    return (data_type) (GSL_SIGN(a - b) == -1? -1.0*(a - b) : (a - b));
}
//
//
//
template<typename data_type> data_type square_module(const data_type &a, const data_type &b)
{
    return (data_type) (GSL_SIGN(a - b) == -1? gsl_pow_2(-1.0*(a - b)) : gsl_pow_2(a - b));
}
//
//
//
template<typename data_type> data_type module(const data_type &a, const data_type &b, const data_type &c)
{
    return (data_type) sqrt(gsl_pow_2(a) + gsl_pow_2(b) + gsl_pow_2(c));
}
