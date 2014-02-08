// ../src/array/array__init_2d_array.cpp ==================================================== //
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
inline void init_2d_array(const unsigned int &row_size, 
                          const unsigned int &column_size)
{
    user_2d_array = new double[row_size*column_size];
    gsl_2d_view = gsl_matrix_view_array(user_2d_array, 
                                        row_size, 
                                        column_size);
    gsl_matrix_set_zero(&gsl_2d_view.matrix);
};