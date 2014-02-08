// ../src/array/array__init_1d_array.cpp ==================================================== //
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
inline void init_1d_array(const unsigned int &row_size)
{
    user_1d_array = new double[row_size];
    gsl_1d_view = gsl_vector_view_array(user_1d_array, 
                                        row_size);
    gsl_vector_set_zero(&gsl_1d_view.vector);
};