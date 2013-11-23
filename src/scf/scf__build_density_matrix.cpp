#include "scf.hpp"
//
//
//
void algorithm::scf::build_density_matrix(array &f_eigenvectors, array &p_matrix)
{
    p_matrix.array::set_all(0.0);
    double density = 0.0;
    unsigned int i = 0;
    #pragma omp parallel for private(i) ordered schedule(dynamic)
    for(i = 1; i <= p_matrix.size_of_row(); ++i)
    {
        unsigned int j = 0;
        #pragma omp parallel for private(j) ordered schedule(dynamic)
        for(j = 1; j <= p_matrix.size_of_column(); ++j)
        {
//
//          CAUTION: The following third inner loop seems do not behave 
//                   properly when parallelized with OpenMP.
//
//                                               Humberto Jr. (08/2013)
//
            for(unsigned int m = 1; m <= p_matrix.size_of_row()/2; ++m)
            {
                #pragma omp atomic
                density += 2.0*f_eigenvectors(i, m)*f_eigenvectors(j, m);
            }
            p_matrix(i, j, density);
            density = 0.0;
        }
    }
}
