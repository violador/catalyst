// ../src/scf/scf__get_energy.cpp =========================================================== //
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
#include "scf.hpp"
//
//
//
double algorithm::scf::get_energy(array &p_matrix, array &h_matrix, array &f_matrix)
{
    double energy = 0.0;
    unsigned int i = 0, j = 0;
    #pragma omp parallel for private(i) reduction(+:energy) ordered schedule(dynamic)
    for(i = 1; i <= p_matrix.array::size_of_row(); ++i)
    {
        #pragma omp parallel for private(j) reduction(+:energy) ordered schedule(dynamic)
        for(j = 1; j <= p_matrix.array::size_of_column(); ++j)
        {
            energy += p_matrix(i, j)*(h_matrix(i, j) + f_matrix(i, j));
        }
    }
    return 0.5*energy;
}