// ../src/file_system/file_system__build_slash.cpp ========================================== //
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
/// @brief A help function that builds on-the-fly the
///        slash "/" or "\" depending the current OS.
//
/// @return A string pattern.
//
inline std::string build_slash()
{
	#if defined(LINUX)
	return std::string("/");
	#elif defined(WIN32)
	return std::string("\\");
	#endif
};
