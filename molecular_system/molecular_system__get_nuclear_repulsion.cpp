#include "molecular_system.hpp"
//
//
//
void molecular_system::get_nuclear_repulsion()
{
    if(atom_types_ready && atom_positions_ready)
    {
        unsigned int i_atom = 0;
        unsigned int i_type = 0;
        #pragma omp parallel for private(i_atom, i_type) ordered schedule(dynamic)
        for(i_atom = 1; i_atom < total_atoms; i_atom++)
        {
            i_type = atom_type.array::get(i_atom);
            unsigned int j_atom = 0;
            unsigned int j_type = 0;
            #pragma omp parallel for private(j_atom, j_type) ordered schedule(dynamic)
            for(j_atom = (i_atom + 1); j_atom <= total_atoms; j_atom++)
            {
                j_type = atom_type.array::get(j_atom);
                #pragma omp critical
                nuclear_repulsion += atomic_number(i_type)*atomic_number(j_type)/interatomic_distance(i_atom, j_atom);
                i_type = j_type = 0;
            }
        }
        nuclear_repulsion_ready = true;
    }
    else
    {
        nuclear_repulsion_ready = false;
    }
}
