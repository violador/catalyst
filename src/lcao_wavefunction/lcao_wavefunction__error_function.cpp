//
//
//
inline double error_function(const double &value)
{
    switch(value <= 0.000001)
    {
        case false: return 0.5*std::sqrt(M_PI/value)*gsl_sf_erf(std::sqrt(value)); break;
        case  true: return 1.0 - (value/3.0); break;
    }
};
