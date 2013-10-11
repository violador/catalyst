#include "sto3g.hpp"
//
//
//
double lcao_wavefunction::sto3g::density_matrix(const unsigned int &i, const unsigned int &j)
{
    if((i > 0) && (i <= number_of_atoms) && (j > 0) && (j <= number_of_atoms))
    {
        return ab_initio_calculation.algorithm::scf::density_matrix(i, j);
    }
    else
    {
        return 0.0;
    }
}
