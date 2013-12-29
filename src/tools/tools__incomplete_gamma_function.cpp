//
//
//
inline double incomplete_gamma_function(const double &a, 
                                        const double &b)
{
    switch(b >= 0.0)
    {
        case false: return 0.0; break;
        case  true: return gsl_sf_gamma_inc(a, b); break;
    }
};
