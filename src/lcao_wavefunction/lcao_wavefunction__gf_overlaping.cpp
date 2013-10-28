//
//
//
inline double gf_overlaping(const double &i_exp,
                            const double &j_exp,
                            const double &ij_distance)
{
    return gsl_sf_exp(-i_exp*j_exp*gsl_pow_2(ij_distance)/(i_exp + j_exp))*std::pow(M_PI/(i_exp + j_exp), 1.5);
};
