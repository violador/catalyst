// ../src/file_system/file_system__rename_dir.cpp =========================================== //
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
/// @param [in] new_name A string pattern with the new directory name
//
/// @brief Renames the current directory and updates the internal data.
//
/// @return None.
//
/// @cite boost_filesystem
//
inline void rename_dir(const std::string &new_name)
{
	boost::filesystem::rename(path, new_name);
	restart_path(new_name);
};
