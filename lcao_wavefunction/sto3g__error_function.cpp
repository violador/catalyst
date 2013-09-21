#include "sto3g.hpp"
//
//
//
double lcao_wavefunction::sto3g::error_function(const double &value)
{
    return ((value <= 0.000001)? 1.0 - (value/3.0) : 0.5*sqrt(M_PI/value)*gsl_sf_erf(sqrt(value)));
}
