// ../src/molecular_system/molecular_system__mass.cpp ======================================= //
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
//
//
//
inline double mass(const unsigned int &atom)
{
    if(atom_positions_ready and (atom > 0) and (atom <= total_atoms))
    {
        periodic_table get(atom_type(atom));
        return get.periodic_table::mass();
    }
    else
    {
        return 0.0;
    }
};
//
//
//
inline double mass()
{
    return atom_positions_ready? total_mass : 0.0;
};