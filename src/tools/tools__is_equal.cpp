// ../src/tools/tools__is_equal.cpp ========================================================= //
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
/// @param [in] a A string pattern
//
/// @param [in] b A string pattern
//
/// @brief Checks if the beginning of the @c b's content fits the contents
///        of @c a.
//
/// @return @c true if @a fits @c b, and @c false otherwise.
//
inline bool is_equal(const std::string &a,
                     const std::string &b)
{
//
/// @note Notice that this function is useful not just to avoid the large @c
///       std::string namespaces, but also because the @c std::string:compare()
///       member function returns the POSIX convention of 0 if the strings fits
///       and 1 otherwise. What is quite annoying inside the C++ bool convention
///       of 0 meaning @c false, and any number different of 0 meaning @c true.
//
	switch((bool) b.std::string::compare(0, pattern_length(a), a))
	{
		case false: return  true; break;
		case  true: return false; break;
	}
};
