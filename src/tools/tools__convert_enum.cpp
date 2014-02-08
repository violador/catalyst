// ../src/tools/tools__convert_enum.cpp ===================================================== //
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
const char* tools::convert_enum(const unsigned int option)
{
    switch(option)
    {
        case basis::STO_1G: return "STO-1G"; break;
        case basis::STO_2G: return "STO-2G"; break;
        case basis::STO_3G: return "STO-3G"; break;
        case basis::STO_6G: return "STO-6G"; break;
                   default: return ""; break;
    }
}
//
//
//
unsigned int tools::convert_enum(const char* option)
{
    if(strcmp(option, "STO-1G"))
    {
        return basis::STO_1G;
    }
    else if(strcmp(option, "STO-2G"))
    {
        return basis::STO_2G;
    }
    else if(strcmp(option, "STO-3G"))
    {
        return basis::STO_3G;
    }
    else if(strcmp(option, "STO-6G"))
    {
        return basis::STO_6G;
    }
    else
    {
        return DEFAULT_BASIS_SET;
    }
}