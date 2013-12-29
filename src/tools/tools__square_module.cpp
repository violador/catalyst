//
//
//
template<typename data_type> 
inline data_type square_module(const data_type &a, 
                               const data_type &b)
{
    switch((a - b) >= 0.0)
    {
        case false: return gsl_pow_2(-1.0*(a - b)); break;
        case  true: return gsl_pow_2(a - b); break;
    }
};
