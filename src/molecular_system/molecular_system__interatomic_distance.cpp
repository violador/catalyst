// ../src/molecular_system/molecular_system__interatomic_distance.cpp ======================= //
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
double molecular_system::interatomic_distance(const unsigned int &first_atom, 
                                              const unsigned int &second_atom)
{
    if(atom_positions_ready 
       and (first_atom > 0) 
       and (first_atom <= total_atoms) 
       and (second_atom > 0) 
       and (second_atom <= total_atoms))
    {
        double a = 0.0, b = 0.0, c = 0.0;
        #pragma omp parallel sections num_threads(3)
        {
            #pragma omp section
            {
                a = gsl_pow_2(position_x(second_atom) - position_x(first_atom));
            }
            #pragma omp section
            {
                b = gsl_pow_2(position_y(second_atom) - position_y(first_atom));
            }
            #pragma omp section
            {
                c = gsl_pow_2(position_z(second_atom) - position_z(first_atom));
            }
        }
        return std::sqrt(a + b + c);
    }
    else if(atom_positions_ready and (first_atom == second_atom))
    {
        return 0.0;
    }
    else
    {
        return 0.0;
    }
}