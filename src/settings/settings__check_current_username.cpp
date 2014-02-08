// ../src/settings/settings__check_current_username.cpp ===================================== //
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
/// @brief Returns the current number of CPUs available.
//
/// @return A string pattern.
//
inline std::string check_current_username()
{
//
//  The Linux version:
	#if defined(LINUX)
	return tools::convert<std::string>(getenv("LOGNAME"));
	#endif
//
//  The Microsoft Windows version:
	#if defined(WIN32)
	return "";
	#endif
//
//  The Apple OS-X version:
	#if defined(OS_X)
	return "";
	#endif
};
