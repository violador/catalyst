// ../src/tools/tools__lower_case.cpp ======================================================= //
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
/// @param [in, out] pattern A string pattern
//
/// @brief Changes the given @c pattern into its lower case form,
///        if any uppercase is found.
//
/// @return None.
//
inline void lower_case(std::string &pattern)
{
//
/// @note Notice that the real meaning of this function is just
///       to avoid the quite large @c std::string namespace.
//
/// @warning The content of the given @c pattern may or may not be
///          modified.
//
	std::transform(pattern.std::string::begin(),
				   pattern.std::string::end(),
				   pattern.std::string::begin(),
				   std::ptr_fun(tolower));
};
