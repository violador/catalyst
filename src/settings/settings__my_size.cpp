// ../src/settings/settings__my_size.cpp ---------------------------------------------------- //
//
//  This file is part of Catalyst lib.
//
//  Catalyst lib is free software: you can redistribute it and/or modify it under the terms 
//  of the GNU General Public License as published by the Free Software Foundation, either 
//  version 3 of the License, or (at your option) any later version.
//
//  Catalyst lib is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
//  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
//  See the GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License along with Catalyst lib. 
//  If not, see <http://www.gnu.org/licenses/>.
//
// ------------------------------------------------------------------------------------------ //
//
//
//
/// @author Humberto Jr. 
//
/// @date 08/2014
//
/// @return The current size of the object in megabytes. 
//
/// @cite
//
inline double my_size()
{
//
/// @note Notice that the current size is almost the sum 
///       of all the members. It is not exactly the size
///       of the object but it will never be less than 
///       that.
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
                                + work_dir_manager.file_system::my_size())*tools::byte_to_megabyte();
};
