#include "molecular_system.hpp"
//
//
//
void molecular_system::get_system_com()
{
    if(atom_types_ready and atom_positions_ready)
    {
        system_com_x = system_com_y = system_com_z = 0.0;
        unsigned int i_atom = 0;
        #pragma omp parallel for private(i_atom) ordered schedule(dynamic)
        for(i_atom = 1; i_atom <= total_atoms; i_atom++)
        {
            periodic_table data(atom_type(i_atom));
            #pragma omp critical
            system_com_x += data.periodic_table::mass()*position_x(i_atom);
            #pragma omp critical
            system_com_y += data.periodic_table::mass()*position_y(i_atom);
            #pragma omp critical
            system_com_z += data.periodic_table::mass()*position_z(i_atom);
        }
        #pragma omp parallel sections
        {
            #pragma omp section
            {
                system_com_x = system_com_x/total_mass;                                               
            }
            #pragma omp section
            {
                system_com_y = system_com_y/total_mass;                                               
            }
            #pragma omp section
            {
                system_com_z = system_com_z/total_mass;
            }
            #pragma omp section
            {
                system_com_ready = true;
            }
        }
    }
    else
    {
        system_com_ready = false;
    }
}
