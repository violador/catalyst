// ../src/scf/scf__energy.cpp =============================================================== //
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
inline double energy() 
{
    return scf_energy[iteration];
};
//
//
//
inline double energy(const unsigned int &given_iteration)
{
    switch((given_iteration >= 1) and (given_iteration <= iteration))
    {
        case false: return 0.0; break;
        case  true: return scf_energy[given_iteration]; break;
    }
}; 