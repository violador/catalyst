//
//
//
template<typename data_type> 
inline data_type module(const data_type &a, const data_type &b)
{
    switch(GSL_SIGN(a - b))
    {
        case  1: return a - b; break;
        case -1: return -1.0*(a - b); break;
        default: return (data_type) 0.0;
    }
};
//
//
//
template<typename data_type> 
inline data_type square_module(const data_type &a, const data_type &b)
{
    switch(GSL_SIGN(a - b))
    {
        case  1: return gsl_pow_2(a - b); break;
        case -1: return gsl_pow_2(-1.0*(a - b)); break;
        default: return (data_type) 0.0;
    }
};
//
//
//
template<typename data_type> 
inline data_type module(const data_type &a, const data_type &b, const data_type &c)
{
    return sqrt(gsl_pow_2(a) + gsl_pow_2(b) + gsl_pow_2(c));
};
