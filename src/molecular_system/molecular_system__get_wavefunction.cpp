#include "molecular_system.hpp"
//
//
//
void molecular_system::get_wavefunction()
{
//
    global_log::file.write_debug_msg("molecular_system::get_wavefunction(): Level of theory = ", 
                                     config -> task_level(task_number));
//
    global_log::file.write("- Task ", task_number, " > STO-3G level of theory");
    lcao_psi.lcao_wavefunction::start_scf_iterations(atom_type, 
                                                     position_x, 
                                                     position_y, 
                                                     position_z, 
                                                     config -> task_level(task_number));
}
