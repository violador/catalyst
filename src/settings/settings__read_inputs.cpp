// ../src/settings/settings__read_inputs.cpp ------------------------------------------------ //
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
#include "settings.hpp"
//
//
//
/// @author Humberto Jr. 
//
/// @date 01/2014
//
/// @return None. This member function dynamically allocates the @c input data member 
///         (an array of @c total_tasks size) and initializes its content.
//
/// @cite
//
void settings::read_inputs()
{
//
/// @note This member function is designed only to help the class constructor and has 
///       no other application so far.
//
/// @warning This function should be invoked only after that @c total_task was properly 
///          initialized. The default value of @c total_task should be 1, in such case, 
///          this function creates the default @c input_list[1] and initializes the 
///          single input.
//
    switch(total_tasks > 1)
    {
        case false:
        {
            input_list = new std::string[1];
            input_list[0] = scan_config_file("input1=", (std::string) "");
        }
        break;
        case true:
        {
            unsigned int i = 0;
            input_list = new std::string[total_tasks];
            #pragma omp parallel for private(i) ordered schedule(dynamic)
            for(i = 1; i <= total_tasks; ++i)
            {
                std::string option = "input"
                                   + tools::convert<std::string>(i)
                                   + "=";
                input_list[i - 1] = scan_config_file(option, (std::string) "");
            }
        }
        break;
    }
}
