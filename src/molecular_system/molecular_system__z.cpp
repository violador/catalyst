// ../src/molecular_system/molecular_system__z.cpp ========================================== //
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
inline double z()
{
    if(system_com_ready)
    {
        return system_com_z;
    }
    else
    {
        get_system_com();
        return system_com_z;
    }
};
//
//
//
inline double z(const unsigned int &option, const unsigned int &atom)
{
    switch(option)
    {
    case 1:
    {
        if(atom_positions_ready and (atom > 0) and (atom <= total_atoms))
        {
            return position_z(atom);
        }
        else
        {
            return 0.0;
        }
    }
    break;
    case 2:
    { 
        if(atom_velocities_ready and (atom > 0) and (atom <= total_atoms))
        {
            return velocity_z(atom);
        }
        else
        {
            return 0.0;
        }
    }
    break;
    default: return 0.0;
    }
};