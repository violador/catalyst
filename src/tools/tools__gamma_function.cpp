//
//
//
inline double gamma_function(const double &a)
{
    switch(a <= 0.0 or a > GSL_SF_GAMMA_XMAX)
    {
        case false: return gsl_sf_gamma(a); break;
        case  true: return 0.0; break;
    }
};
