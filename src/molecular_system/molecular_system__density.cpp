// ../src/molecular_system/molecular_system__density.cpp ==================================== //
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
inline double density(const unsigned int &i, const unsigned int &j)
{
/*
    if(ab_initio_ready 
       and (i > 0) 
       and (i <= number_of_atoms()) 
       and (j > 0) 
       and (j <= number_of_atoms()))
    {
        return (wavefunction -> density_matrix(i, j));
    }
    else
    {
        get_wavefunction();
        return (wavefunction -> density_matrix(i, j));
    }
*/
    return 0.0;
};