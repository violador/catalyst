// ../src/array/array__set_transpose.cpp ==================================================== //
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
inline void set_transpose()
{
    switch(is_2d_array 
           and (not deleted_array) 
           and (not is_const_array)
           and is_square_array)
    {
        case true:
        gsl_matrix_transpose(&gsl_2d_view.matrix);
        is_transposed? is_transposed = false : is_transposed = true;
        break;
    }
};