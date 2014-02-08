// ../src/tools/tools__comment_line.cpp ===================================================== //
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
/// @brief Checks if the given @c pattern is a comment line tagged
///        with the @c # symbol at the beginning.
//
/// @return @c true if the given @c pattern has the @c #, and @c
///         false otherwise.
//
inline bool comment_line(const std::string &pattern)
{
	switch((bool) pattern.std::string::compare(0, 1, "#"))
	{
		case false: return  true; break;
		case  true: return false; break;
	}
};
