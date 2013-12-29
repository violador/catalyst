//
//
//
inline double double_factorial(const int &a)
{
    switch((a <= 0) or (a > GSL_SF_DOUBLEFACT_NMAX))
    {
        case false: return gsl_sf_doublefact(a); break;
        case  true: return 1.0; break;
    }
};
