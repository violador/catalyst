// ../src/tools/tools__first_gf.cpp ========================================================= //
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
#include "tools.hpp"
//
//
//
unsigned int tools::first_gf(const unsigned int &given_level, 
                             const unsigned int &given_orbital)
{
    switch(given_level)
    {
        case STO3G: 
        {
            switch(given_orbital)
            {
                case  SUB_SHELL_1s: return 1; break;
                case  SUB_SHELL_2s: return 4; break;
                case SUB_SHELL_2px: return 7; break;
                case SUB_SHELL_2py: return 7; break;
                case SUB_SHELL_2pz: return 7; break;
                           default: return 0; break;
            }
        }
        break;
        default: return 0;
    }
}