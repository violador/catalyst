// ../src/basis_set/basis_set__constructor.cpp ============================================== //
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
#include "basis_set.hpp"
//
//
//
/// @param [in] element The number of the atom type (chemical element).
//
/// @param [in] level The level of theory.
//
/// @brief The standard @c basis_set constructor, that allocates the set
///        of exponents and coefficients for each primitive function
///        for a given atom type and level of theory.
//
/// @return None.
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
