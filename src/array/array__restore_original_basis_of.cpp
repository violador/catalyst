// ../src/array/array__restore_original_basis_of.cpp ======================================== //
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
void array::restore_original_basis_of(array &given_array)
{
    switch(not given_array.is_const_array)
    {
        case true:
        double *array_buffer = new double[given_array.sizeof_row*given_array.sizeof_column];
        gsl_matrix_view gsl_buffer_view = gsl_matrix_view_array(array_buffer, given_array.sizeof_row, given_array.sizeof_column);
        gsl_matrix_set_zero(&gsl_buffer_view.matrix);
        gsl_matrix_swap(&gsl_buffer_view.matrix, &given_array.gsl_2d_view.matrix);
//
        cblas_dgemm(CblasRowMajor,
                    CblasNoTrans,
                    CblasNoTrans,
                    sizeof_row,
                    sizeof_column,
                    given_array.sizeof_row,
                    1.0,
                    user_2d_array,
                    sizeof_column,
                    array_buffer,
                    given_array.sizeof_column,
                    1.0,
                    given_array.user_2d_array,
                    given_array.sizeof_column);
//
        delete[] array_buffer;
        break;
    }
}