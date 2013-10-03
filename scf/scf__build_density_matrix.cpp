#include "scf.hpp"
//
//
//
void algorithm::scf::build_density_matrix(array &f_eigenvectors, array &p_matrix)
{
    p_matrix.array::set_all(0.0);
    double density = 0.0;
    unsigned int i = 0, j = 0, m = 0;
    #pragma omp parallel for private(i, j, m) ordered schedule(dynamic)
    for(i = 1; i <= p_matrix.size_of_row(); i++)
    {
        #pragma omp parallel for private(j, m) ordered schedule(dynamic)
        for(j = 1; j <= p_matrix.size_of_column(); j++)
        {
//
//          CAUTION: The following third inner loop seems do not behave 
//                   properly when parallelized with OpenMP.
//
//                                               Humberto Jr. (08/2013)
//
            for(m = 1; m <= (p_matrix.size_of_row()/2); m++)
            {
                #pragma omp atomic
                density += 2.0*f_eigenvectors.get(i, m)*f_eigenvectors.get(j, m);
            }
            p_matrix.set(i, j, density);
            density = 0.0;
        }
    }
}
