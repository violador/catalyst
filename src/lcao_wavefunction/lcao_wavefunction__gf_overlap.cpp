//
//
//
inline double gf_overlap(const double &a, // The m-th gf exponent.
                         const double &b, // The n-th gf exponent.
                         const double &c) // The i-j atomic distance.
{
    return gsl_sf_exp(-a*b*gsl_pow_2(c)/(a + b))*std::pow(M_PI/(a + b), 1.5);
};
