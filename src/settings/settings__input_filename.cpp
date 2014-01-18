// ../src/settings/settings__input_filename.cpp --------------------------------------------- //
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
/// @date 01/2014
//
/// @return The input filename of the given @c task. 
//
/// @cite
//
inline std::string input_filename(const unsigned int &task)
{
    switch(task <= total_tasks) 
    {
        case true:
        input_manager.file_system::init(work_dir(), input_list[task - 1]);
        switch(input_manager.file_system::exists() 
               and input_manager.file_system::is_file())
        {
            case true: 
            return input_manager.file_system::full_name(); 
            break;
        }
        break;
    }
    return "";
};
