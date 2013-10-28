//
//
//
inline double interatomic_distance(const double &a,
                                   const double &b,
                                   const double &c,
                                   const double &d,
                                   const double &e,
                                   const double &f)
{
    return std::sqrt(gsl_pow_2(d - a) + gsl_pow_2(e - b) + gsl_pow_2(f - c));
};
