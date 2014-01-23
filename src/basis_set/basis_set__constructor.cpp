// ../src/basis_set/basis_set__constructor.cpp ---------------------------------------------- //
//
//  This file is part of Catalyst lib.
//
//  Catalyst lib is free software: you can redistribute it and/or modify it under the terms 
//  of the GNU General Public License as published by the Free Software Foundation, either 
//  version 3 of the License, or (at your option) any later version.
//
//  Catalyst lib is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
//  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
//  See the GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License along with Catalyst lib. 
//  If not, see <http://www.gnu.org/licenses/>.
//
// ------------------------------------------------------------------------------------------ //
#include "basis_set.hpp"
//
//
//
/// @author Humberto Jr. 
//
/// @date 10/2013
//
/// @return None. 
//
/// @cite
//
basis_set::basis_set(const unsigned int &element, 
                     const unsigned int &level): current_element(element),
                                                 current_level(level),
                                                 current_set_size(init_set_size()),
                                                 iter(1),
                                                 coeff(NULL),
                                                 expon(NULL)
{
    switch(current_level)
    {
        case basis::STO_3G:
        {
            #pragma omp parallel sections num_threads(2)
            {
                #pragma omp section
                {
                    init_sto3g_coeff();
                }
                #pragma omp section
                {
                    init_sto3g_expon();
                }
            }
        }
        break;
    }
}
