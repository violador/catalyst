#include "scf.hpp"
//
//
//
double algorithm::scf::get_energy(array &p_matrix, array &h_matrix, array &f_matrix)
{
    double energy = 0.0;
    unsigned int i = 0, j = 0;
    #pragma omp parallel for private(i) reduction(+:energy) ordered schedule(dynamic)
    for(i = 1; i <= p_matrix.array::size_of_row(); ++i)
    {
        #pragma omp parallel for private(j) reduction(+:energy) ordered schedule(dynamic)
        for(j = 1; j <= p_matrix.array::size_of_column(); ++j)
        {
            energy += p_matrix(i, j)*(h_matrix(i, j) + f_matrix(i, j));
        }
    }
    return 0.5*energy;
}
