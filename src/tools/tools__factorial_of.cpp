//
//
//
inline double factorial_of(const int &given_value)
{
    switch((given_value <= 0) or (given_value > GSL_SF_FACT_NMAX))
    {
        case false: return gsl_sf_fact(given_value); break;
        case  true: return 1.0; break;
    }
};
