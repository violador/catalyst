//
//
//
inline double gf_product_const(const double &i_coeff,
                               const double &j_coeff,
                               const double &ij_distance)
{
    return gsl_sf_exp((-i_coeff*j_coeff/(i_coeff + j_coeff))*gsl_pow_2(ij_distance));
};
