// ../src/settings/settings__work_dir.cpp --------------------------------------------------- //
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
/// @date 05/2013
//
/// @return The full path of the work directory if it exists and is a directory 
///         indeed. Otherwise returns a empty string.
//
/// @cite
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
