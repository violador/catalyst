// ../src/settings/settings__check_current_time.cpp ========================================= //
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
/// @brief Return the current time in the following format: @c "Sat Oct 12 00:24:17 2013".
//
/// @return A string pattern.
//
inline std::string check_current_time()
{
	time_t current_time = time(0);
	return tools::convert<std::string>(ctime(&current_time));
};
