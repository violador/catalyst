#include "molecular_system.hpp"
//
//
//
void molecular_system::get_wavefunction(unsigned int theory_level)
{
    switch(theory_level)
    {
    case 1:
    {
        if(atom_types_ready and atom_positions_ready)
        {
            //log_file -> report("\n- Task ", task_number, " > STO-3G level of theory\n");
            lcao_wavefunction::sto3g psi(total_atoms, position_x, position_y, position_z, atom_type, *config);
            wavefunction = &psi.lcao_wavefunction::sto3g::ab_initio_calculation;
            ab_initio_ready = true;
        }
    }
    break;
/*
    case 2: // Use this template to add new levels.
    {
    }
    break;
*/
    }
}
