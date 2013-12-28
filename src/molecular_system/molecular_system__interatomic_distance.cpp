#include "molecular_system.hpp"
//
//
//
double molecular_system::interatomic_distance(const unsigned int &first_atom, 
                                              const unsigned int &second_atom)
{
    if(atom_positions_ready 
       and (first_atom > 0) 
       and (first_atom <= total_atoms) 
       and (second_atom > 0) 
       and (second_atom <= total_atoms))
    {
        double a = 0.0, b = 0.0, c = 0.0;
        #pragma omp parallel sections num_threads(3)
        {
            #pragma omp section
            {
                a = gsl_pow_2(position_x(second_atom) - position_x(first_atom));
            }
            #pragma omp section
            {
                b = gsl_pow_2(position_y(second_atom) - position_y(first_atom));
            }
            #pragma omp section
            {
                c = gsl_pow_2(position_z(second_atom) - position_z(first_atom));
            }
        }
        return std::sqrt(a + b + c);
    }
    else if(atom_positions_ready and (first_atom == second_atom))
    {
        return 0.0;
    }
    else
    {
        return 0.0;
    }
}
