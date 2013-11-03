#include "lcao_wavefunction.hpp"
//
//
//
void lcao_wavefunction::build_density_matrix(array &p_matrix,
                                             array &type,
                                             array &x,
                                             array &y,
                                             array &z,
                                             const unsigned int given_theory_level)
{
//
    switch(p_matrix.array::check_if(IS_CONSTANT))
    {
        case false: check_matrix_size(p_matrix, type.array::size_of_row()); break;
        case  true: return; break;
    }
//
    #pragma omp parallel sections num_threads(2)
    {
        #pragma omp section
        {
            build_hamiltonian_matrix(h_matrix,
                                     type,
                                     x,
                                     y,
                                     z,
                                     given_theory_level);
        }
    }
}
