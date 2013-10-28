//
//
//
template<typename data_type> 
inline data_type module(const data_type &a, const data_type &b)
{
    switch(GSL_SIGN(a - b) == -1)
    {
        case false: return a - b; break;
        case  true: return -1.0*(a - b); break;
    }
};
//
//
//
template<typename data_type> 
inline data_type square_module(const data_type &a, const data_type &b)
{
    switch(GSL_SIGN(a - b) == -1)
    {
        case false: return gsl_pow_2(a - b); break;
        case  true: return gsl_pow_2(-1.0*(a - b)); break;
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
