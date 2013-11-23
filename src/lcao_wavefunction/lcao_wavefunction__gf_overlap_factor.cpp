//
//
//
inline double gf_overlap_factor(const double &a, // The m-th gf exponent.
                                const double &b, // The n-th gf exponent.
                                const double &c) // The i-j atomic distance.
{
    return gsl_sf_exp(-a*b*gsl_pow_2(c)/(a + b));
};
