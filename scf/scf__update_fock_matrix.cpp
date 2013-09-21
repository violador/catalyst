#include "scf.hpp"
//
//
//
void algorithm::scf::update_fock_matrix(array &f_matrix, array &h_matrix, array &p_matrix, array &two_electrons_interaction)
{
    double energy = 0.0;
    f_matrix.set_all(0.0);
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int m = 0;
    unsigned int n = 0;
    for(i = 1; i <= h_matrix.size_of_row(); i++)
    {
        for(j = 1; j <= h_matrix.size_of_column(); j++)
        {
            for(m = 1; m <= h_matrix.size_of_row(); m++)
            {
                #pragma omp parallel for private(n) ordered schedule(dynamic)
                for(n = 1; n <= h_matrix.size_of_column(); n++)
                {
                    #pragma omp atomic
                    energy += p_matrix.get(m, n)
                            * (two_electrons_interaction.get(i, j, n, m) - 0.5*two_electrons_interaction.get(i, m, n, j));
                }
            }
            f_matrix.set(i, j, h_matrix.get(i, j) + energy);
            energy = 0.0;
        }
    }
}
