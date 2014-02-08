// ../src/tools/tools__byte_to_kilobyte.cpp ================================================= //
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
/// @brief The factor for conversions from bytes to kilobytes.
//
/// @return @f$ 0.0009765625 @f$
//
/// @cite
//
inline const double byte_to_kilobyte()
{
	return 0.0009765625;
};
//
//
//
/// @param [in] a A templated type number in byte units.
//
/// @brief Converts the given @c a to kilobyte units.
//
/// @return @f$ a \times 0.0009765625 @f$
//
/// @cite
//
template<typename data_type>
inline double byte_to_kilobyte(const data_type &a)
{
	return a*0.0009765625;
};
