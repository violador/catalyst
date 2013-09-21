#include "sto3g.hpp"
//
//
//
double lcao_wavefunction::sto3g::interatomic_distance(const unsigned int &first_atom, const unsigned int &second_atom)
{
    if((first_atom > 0) && (first_atom <= number_of_atoms) && (second_atom > 0) && (second_atom <= number_of_atoms))
    {
        return sqrt(gsl_pow_2((x -> get(second_atom)) - (x -> get(first_atom)))
                  + gsl_pow_2((y -> get(second_atom)) - (y -> get(first_atom)))
                  + gsl_pow_2((z -> get(second_atom)) - (z -> get(first_atom))));
    }
    else if(first_atom == second_atom)
    {
        return 0.0;
    }
    else
    {
        return 0.0;
    }
}
