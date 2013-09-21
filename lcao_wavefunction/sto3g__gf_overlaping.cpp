#include "sto3g.hpp"
//
//
//
double lcao_wavefunction::sto3g::gf_overlaping(const double &i_exp,
                                               const double &j_exp,
                                               const double &ij_distance)
{
    return gsl_sf_exp(-i_exp*j_exp*gsl_pow_2(ij_distance)/(i_exp + j_exp))*pow(M_PI/(i_exp + j_exp), 1.5);
}
