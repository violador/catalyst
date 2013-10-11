#include "scf.hpp"
//
//
//
double algorithm::scf::get_energy(array &p_matrix, 
                                  array &h_matrix, 
                                  array &f_matrix)
{
    double energy = 0.0;
    for(unsigned int i = 1; i <= p_matrix.size_of_row(); i++)
    {
        for(unsigned int j = 1; j <= p_matrix.size_of_column(); j++)
        {
            energy += p_matrix.get(i, j)*(h_matrix.get(i, j) + f_matrix.get(i, j));
        }
    }
    return 0.5*energy;
}
