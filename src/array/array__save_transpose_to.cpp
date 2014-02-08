// ../src/array/array__save_transpose_to.cpp ================================================ //
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
inline void save_transpose_to(array &given_array)
{
    switch(this -> is_2d_array 
           and given_array.is_2d_array 
           and (not given_array.is_const_array))
    {
        case true:
        switch((this -> sizeof_row not_eq given_array.sizeof_row) or (this -> sizeof_column not_eq given_array.sizeof_column))
        {
            case false: break;
            case  true: given_array.resize_array(this -> sizeof_row, this -> sizeof_column); break;
        }
        gsl_matrix_transpose_memcpy(&given_array.gsl_2d_view.matrix, &this -> gsl_2d_view.matrix);
        break;
    }
};