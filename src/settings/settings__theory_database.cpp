// ../src/settings/settings__theory_database.cpp ============================================ //
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
#include "settings.hpp"
//
//
//
std::string settings::theory_database(const unsigned int &option)
{
    switch(option)
    {
        case 1: return "STO-3G"; break;
        case 2: return "STO-2G"; break;
        case 3: return "STO-1G"; break;
       default: return "";
    }
};
//
//
//
unsigned int settings::theory_database(const std::string &option)
{
    unsigned int i = 0, theory_number = 0;
    #pragma omp parallel for private(i) ordered schedule(dynamic)
    for(i = 1; i <= 3; i++)
    {
        switch(option.compare(theory_database(i)))
        {
            case false: theory_number = i; break;
            case  true: break;
        }
    }
    return theory_number;
};