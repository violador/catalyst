// ../src/settings/settings__check_current_disk_space.cpp =================================== //
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
/// @brief Returns the current disk/partition space in gigabytes.
///        The value is from the disk/partition that contains the
///        current scratch directory.
//
/// @return A non-negative real number.
//
inline double check_current_disk_space()
{
	return scratch_dir_manager.file_system::check_disk_space();
};
