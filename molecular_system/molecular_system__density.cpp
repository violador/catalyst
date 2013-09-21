#include "molecular_system.hpp"
//
//
//
double molecular_system::density(const unsigned int &i, const unsigned int &j)
{
    if(ab_initio_ready 
       and (i > 0) 
       and (i <= number_of_atoms()) 
       and (j > 0) 
       and (j <= number_of_atoms()))
    {
        return (wavefunction -> density_matrix(i, j));
    }
    else
    {
        get_wavefunction(config -> wavefunction_type(task_number));
        return (wavefunction -> density_matrix(i, j));
    }
}
