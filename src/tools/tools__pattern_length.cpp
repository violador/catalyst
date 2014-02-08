// ../src/tools/tools__pattern_length.cpp =================================================== //
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
/// @param [in] pattern A string pattern
//
/// @brief Returns the length of the given @c pattern.
//
/// @return A non-negative integer number.
//
inline unsigned int pattern_length(const std::string &pattern)
{
//
/// @note Notice that the real meaning of this function is just to avoid the
///       quite large @c std::string namespace.
//
	return pattern.std::string::length();
}
