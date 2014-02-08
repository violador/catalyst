// ../src/settings/settings__work_dir.cpp =================================================== //
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
/// @brief Returns the full path of the work directory if it exists and is a directory
///        indeed. Otherwise returns a empty string.
//
/// @return A string pattern.
//
inline std::string work_dir()
{
	switch(work_dir_manager.file_system::exists()
			and work_dir_manager.file_system::is_dir())
	{
		case false: return ""; break;
		case  true: return work_dir_manager.file_system::full_name(); break;
	}
};
