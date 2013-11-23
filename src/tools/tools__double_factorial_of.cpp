//
//
//
inline double double_factorial_of(const int &given_value)
{
    switch((given_value <= 0) or (given_value > GSL_SF_DOUBLEFACT_NMAX))
    {
        case false: return gsl_sf_doublefact(given_value); break;
        case  true: return 1.0; break;
    }
};
