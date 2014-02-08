// ../src/molecular_system/molecular_system__get_wavefunction.cpp =========================== //
//
// Catalyst Lib is free software:  you can redistribute it and/or modifyit under the terms of
// the GNU General Public License as published bythe Free Software Foundation, either version
// 3 of the License, or(at your option) any later version.
//
// Catalyst Lib is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
// without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with Catalyst Lib.
// If not, see <http://www.gnu.org/licenses/>.
//
// ========================================================================================== //
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