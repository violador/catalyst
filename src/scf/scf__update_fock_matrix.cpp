#include "scf.hpp"
//
//
//
void algorithm::scf::update_fock_matrix(array &f_matrix, 
                                        array &h_matrix, 
                                        array &p_matrix, 
                                        array &v_matrix)
{
//
    f_matrix.array::set_all(0.0);
    double energy = 0.0;
//
    unsigned int i = 0;
    for(i = 1; i <= h_matrix.array::size_of_row(); i++)
    {
        unsigned int j = 0;
        for(j = 1; j <= h_matrix.array::size_of_column(); j++)
        {
            unsigned int m = 0;
            #pragma omp parallel for private(m) ordered schedule(dynamic)
            for(m = 1; m <= h_matrix.array::size_of_row(); m++)
            {
                unsigned int n = 0;
                #pragma omp parallel for private(n) ordered schedule(dynamic)
                for(n = 1; n <= h_matrix.array::size_of_column(); n++)
                {
                    #pragma omp atomic
                    energy += p_matrix(m, n)*(v_matrix(i, j, n, m) - 0.5*v_matrix(i, m, n, j));
                }
            }
            f_matrix(i, j, h_matrix(i, j) + energy);
            energy = 0.0;
        }
    }
}
