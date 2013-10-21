#include "molecular_system.hpp"
//
//
//
void molecular_system::get_wavefunction()
{
    global_log::file.write_debug_msg("molecular_system::get_wavefunction(): Theory level = ", config -> task_level(task_number));
    switch(config -> task_level(task_number))
    {
        case 1:
        {
            if(atom_types_ready and atom_positions_ready)
            {
                global_log::file.write("- Task ", task_number, " > STO-3G level of theory");
                lcao_wavefunction::sto3g psi(total_atoms, position_x, position_y, position_z, atom_type, *config);
                //wavefunction = &psi.lcao_wavefunction::sto3g::ab_initio_calculation;
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
