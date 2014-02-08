// ../src/array/array__reset_properties.cpp ================================================= //
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
#include "array.hpp"
//
//
//
void array::reset_properties()
{
    sizeof_row = 0;
    sizeof_column = 0;
    sizeof_1st_layer = 0;
    sizeof_2nd_layer = 0;
    is_1d_array = true;
    is_2d_array = false;
    is_3d_array = false;
    is_4d_array = false;
    is_const_array = false;
    is_square_array = false;
    is_transposed = false;
    deleted_array = true;
    array_name = DEFAULT_ARRAY_NAME;
    config = &global_settings::config;
}
//
//
//
void array::reset_properties(const unsigned int &row_size)
{
    sizeof_row = row_size;
    sizeof_column = 0;
    sizeof_1st_layer = 0;
    sizeof_2nd_layer = 0;
    is_1d_array = true;
    is_2d_array = false;
    is_3d_array = false;
    is_4d_array = false;
    is_const_array = false;
    is_square_array = false;
    is_transposed = false;
    deleted_array = false;
    array_name = DEFAULT_ARRAY_NAME;
    config = &global_settings::config;
}
//
//
//
void array::reset_properties(const unsigned int &row_size,
                             const unsigned int &column_size)
{
    sizeof_row = row_size;
    sizeof_column = column_size;
    sizeof_1st_layer = 0;
    sizeof_2nd_layer = 0;
    is_1d_array = false;
    is_2d_array = true;
    is_3d_array = false;
    is_4d_array = false;
    is_const_array = false;
    is_square_array = (row_size == column_size? true : false);
    is_transposed = false;
    deleted_array = false;
    array_name = DEFAULT_ARRAY_NAME;
    config = &global_settings::config;
}
//
//
//
void array::reset_properties(const unsigned int &row_size,
                             const unsigned int &column_size,
                             const unsigned int &layer_size)
{
    sizeof_row = row_size;
    sizeof_column = column_size;
    sizeof_1st_layer = layer_size;
    sizeof_2nd_layer = 0;
    is_1d_array = false;
    is_2d_array = false;
    is_3d_array = true;
    is_4d_array = false;
    is_const_array = false;
    is_square_array = false;
    is_transposed = false;
    deleted_array = false;
    array_name = DEFAULT_ARRAY_NAME;
    config = &global_settings::config;
}
//
//
//
void array::reset_properties(const unsigned int &row_size,
                             const unsigned int &column_size,
                             const unsigned int &layer1_size,
                             const unsigned int &layer2_size)
{
    sizeof_row = row_size;
    sizeof_column = column_size;
    sizeof_1st_layer = layer1_size;
    sizeof_2nd_layer = layer2_size;
    is_1d_array = false;
    is_2d_array = false;
    is_3d_array = false;
    is_4d_array = true;
    is_const_array = false;
    is_square_array = false;
    is_transposed = false;
    deleted_array = false;
    array_name = DEFAULT_ARRAY_NAME;
    config = &global_settings::config;
}