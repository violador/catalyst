// ../src/array/array__create_array.cpp ===================================================== //
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
// ../src/array/array__create_array.cpp ----------------------------------------------------- //
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
/// @date 07/2013
//
/// @return None. Initializes the current 1D array with the 
///               given size.
//
/// @cite
//
inline void create_array(const unsigned int &row_size)
{
//
/// @note Notice this function is valid for deleted arrays only.
//
    switch(deleted_array)
    {
        case true: 
        deleted_array = false;
        sizeof_row = row_size;
        init_1d_array(row_size);
        break;
    }
};
//
//
//
/// @author Humberto Jr. 
//
/// @date 07/2013
//
/// @return None. Initializes the current 2D array with the 
///               given sizes.
//
/// @cite
//
inline void create_array(const unsigned int &row_size,
                         const unsigned int &column_size)
{
//
/// @note Notice this function is valid for deleted arrays only.
//
    switch(deleted_array)
    {
        case true: 
        deleted_array = false;
        sizeof_row = row_size;
        sizeof_column = column_size;
        init_2d_array(row_size, column_size);
        row_size == column_size? is_square_array = true : is_square_array = false;
        break;
    }
};
//
//
//
/// @author Humberto Jr. 
//
/// @date 07/2013
//
/// @return None. Initializes the current 3D array with the 
///               given sizes.
//
/// @cite
//
inline void create_array(const unsigned int &row_size,
                         const unsigned int &column_size,
                         const unsigned int &layer1_size)
{
//
/// @note Notice this function is valid for deleted arrays only.
//
    switch(deleted_array)
    {
        case true: 
        deleted_array = false;
        sizeof_row = row_size;
        sizeof_column = column_size;
        sizeof_1st_layer = layer1_size;
        init_3d_array(row_size, column_size, layer1_size);
        break;
    }
};
//
//
//
/// @author Humberto Jr. 
//
/// @date 07/2013
//
/// @return None. Initializes the current 4D array with the 
///               given sizes.
//
/// @cite
//
inline void create_array(const unsigned int &row_size,
                         const unsigned int &column_size,
                         const unsigned int &layer1_size,
                         const unsigned int &layer2_size)
{
//
/// @note Notice this function is valid for deleted arrays only.
//
    switch(deleted_array)
    {
        case true: 
        deleted_array = false;
        sizeof_row = row_size;
        sizeof_column = column_size;
        sizeof_1st_layer = layer1_size;
        sizeof_2nd_layer = layer2_size;
        init_4d_array(row_size, column_size, layer1_size, layer2_size);
        break;
    }
};