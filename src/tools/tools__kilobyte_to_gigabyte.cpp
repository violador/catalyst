// ../src/tools/tools__kilobyte_to_gigabyte.cpp ============================================= //
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
/// @brief Returns the conversion factor from kilobytes to gigabytes.
//
/// @return 0.000000953674316
//
inline const double kilobyte_to_gigabyte()
{
	return 0.000000953674316;
};
//
//
//
/// @param [in] a A templated type number in kilobyte units.
//
/// @brief Converts the given @c a to gigabyte units.
//
/// @return @f$ a \times 0.000000953674316 @f$
//
template<typename data_type>
inline double kilobyte_to_gigabyte(const data_type &a)
{
	return a*0.000000953674316;
};
