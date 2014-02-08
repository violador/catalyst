// ../src/molecular_system/molecular_system__get_nuclear_repulsion.cpp ====================== //
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
void molecular_system::get_nuclear_repulsion()
{
    if(atom_types_ready and atom_positions_ready)
    {
        unsigned int i_atom = 0, i_type = 0;
        #pragma omp parallel for private(i_atom, i_type) ordered schedule(dynamic)
        for(i_atom = 1; i_atom < total_atoms; ++i_atom)
        {
            i_type = atom_type(i_atom);
            unsigned int j_atom = 0, j_type = 0;
            #pragma omp parallel for private(j_atom, j_type) ordered schedule(dynamic)
            for(j_atom = (i_atom + 1); j_atom <= total_atoms; ++j_atom)
            {
                j_type = atom_type(j_atom);
                #pragma omp critical
                nuclear_repulsion += atomic_number(i_type)*atomic_number(j_type)
                                   / interatomic_distance(i_atom, j_atom);
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