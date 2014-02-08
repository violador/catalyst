// ../src/settings/settings__my_size.cpp ==================================================== //
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
/// @brief Returns the size of the current object in kilobytes.
//
/// @return A non-negative real number.
//
inline double my_size()
{
//
/// @note Notice that the current size is almost the sum
///       of all the members. It is not exactly the size
///       of the object but it will never be less than
///       that.
//
    return (sizeof(config_file) + sizeof(total_tasks)
								+ sizeof(output_mode_on)
								+ sizeof(vibration_mode_on)
								+ sizeof(rotation_mode_on)
								+ sizeof(translation_mode_on)
								+ sizeof(debug_mode_on)
								+ sizeof(highend_mode_on)
								+ sizeof(standby_mode_on)
								+ sizeof(temp_files_on)
								+ sizeof(logging_matrices)
								+ sizeof(precision)
								+ sizeof(scf_criteria)
								+ total_tasks*sizeof(input_list)
								+ total_tasks*sizeof(level_list)
								+ input_manager.file_system::my_size()
								+ scratch_dir_manager.file_system::my_size()
								+ work_dir_manager.file_system::my_size())
			*tools::byte_to_kilobyte();
};
