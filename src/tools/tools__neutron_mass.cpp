// ../src/tools/tools__neutron_mass.cpp ===================================================== //
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
/// @brief Returns the neutron mass in the standard MKSA system.
//
/// @return The GSL macro @c GSL_CONST_MKSA_MASS_NEUTRON.
//
/// @cite gsl
//
inline const double neutron_mass()
{
	return GSL_CONST_MKSA_MASS_NEUTRON;
};
