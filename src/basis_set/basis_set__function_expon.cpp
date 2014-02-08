// ../src/basis_set/basis_set__function_expon.cpp =========================================== //
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
/// @param [in] primitive The number of the primitive function.
//
/// @brief Returns the exponent value of the given primitive
///        function. Or returns zero, if the given primitive
///        functions number is out of the current set size.
//
/// @return A real number.
//
inline double &function_expon(const unsigned int &primitive)
{
	switch(primitive <= current_set_size)
	{
		case false: return expon[0]; break;
		case  true: return expon[primitive]; break;
	}
};
//
//
//
/// @brief Returns the exponent value of the primitive function
///        given by the internal iterator.
//
/// @return A real number.
//
inline double &function_expon()
{
	return expon[iter];
};
