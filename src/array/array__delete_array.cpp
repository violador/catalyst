// ../src/array/array__delete_array.cpp ===================================================== //
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
// ../src/array/array__delete_array.cpp ----------------------------------------------------- //
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
#include "array.hpp"
//
//
//
/// @author Humberto Jr.
//
/// @date 07/2013
//
/// @return None. Deallocates the current array and 
///         reset its properties.
//
/// @cite
//
void array::delete_array()
{
//
/// @note Valid for all array types. Notice also that 
///       after invoke this function, @c delete_array 
///       @c = @c true. This function do not replace 
///       the class desctructor which will be invoked 
///       by default at the right moment.
//
    #pragma omp parallel sections num_threads(5)
    {
        #pragma omp section
        {
            switch(is_1d_array)
            {
                case true:
                delete_1d_array();
                deleted_array = true;
                break;
            }
        }
        #pragma omp section
        {
            switch(is_2d_array)
            {
                case true:
                delete_2d_array();
                deleted_array = true;
                break;
            }
        }
        #pragma omp section
        {
            switch(is_3d_array)
            {
                case true:
                delete_3d_array();
                deleted_array = true;
                break;
            }
        }
        #pragma omp section
        {
            switch(is_4d_array)
            {
                case true:
                delete_4d_array();
                deleted_array = true;
                break;
            }
        }
        #pragma omp section
        {
            reset_properties();
        }
    }
}