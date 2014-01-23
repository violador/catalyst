// ../src/settings/settings__task_level.cpp ------------------------------------------------- //
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
/// @return The current level of theory (its enum) for a 
///         given task.
//
/// @cite
//
inline unsigned int &task_level(unsigned int &task)
{
    switch(task <= total_tasks)
    {
        case false: return level_list[0]; break;
        case  true: return level_list[task - 1]; break;
    }
};
