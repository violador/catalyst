// ../src/tools/tools__angular_component_.cpp =============================================== //
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
inline unsigned int angular_component_x(const unsigned int &given_orbital)
{
    switch(given_orbital)
    {
        case  SUB_SHELL_1s: return 0; break;
        case  SUB_SHELL_2s: return 0; break;
        case SUB_SHELL_2px: return 1; break;
        case SUB_SHELL_2py: return 0; break;
        case SUB_SHELL_2pz: return 0; break;
                   default: return 0; 
    }
};
//
//
//
inline unsigned int angular_component_y(const unsigned int &given_orbital)
{
    switch(given_orbital)
    {
        case  SUB_SHELL_1s: return 0; break;
        case  SUB_SHELL_2s: return 0; break;
        case SUB_SHELL_2px: return 0; break;
        case SUB_SHELL_2py: return 1; break;
        case SUB_SHELL_2pz: return 0; break;
                   default: return 0; 
    }
};
//
//
//
inline unsigned int angular_component_z(const unsigned int &given_orbital)
{
    switch(given_orbital)
    {
        case  SUB_SHELL_1s: return 0; break;
        case  SUB_SHELL_2s: return 0; break;
        case SUB_SHELL_2px: return 0; break;
        case SUB_SHELL_2py: return 0; break;
        case SUB_SHELL_2pz: return 1; break;
                   default: return 0; 
    }
};