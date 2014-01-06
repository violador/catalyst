//
//
//
inline double factorial(const int &a)
{
    switch(a <= 0 or a > GSL_SF_FACT_NMAX)
    {
        case false: return gsl_sf_fact(a); break;
        case  true: return 1.0; break;
    }
};
