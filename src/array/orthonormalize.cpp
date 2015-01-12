// ../src/array/array__orthonormalize.cpp =================================================== //
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
void array::orthonormalize(array &given_array)
{
    switch(not given_array.constant)
    {
        case true:
        double *array_buffer = new double[given_array.rank1*given_array.rank2];
        gsl_matrix_view gsl_buffer_view = gsl_matrix_view_array(array_buffer, given_array.rank1, given_array.rank2);
        gsl_matrix_set_zero(&gsl_buffer_view.matrix);
        gsl_matrix_swap(&gsl_buffer_view.matrix, &given_array.gsl_2d_view.matrix);
//
        cblas_dgemm(CblasRowMajor,
                    CblasTrans,
                    CblasNoTrans,
                    rank1,
                    rank2,
                    given_array.rank1,
                    1.0,
                    data2,
                    rank2,
                    array_buffer,
                    given_array.rank2,
                    1.0,
                    given_array.data2,
                    given_array.rank2);
//
        gsl_matrix_set_zero(&gsl_buffer_view.matrix);
        gsl_matrix_swap(&gsl_buffer_view.matrix, &given_array.gsl_2d_view.matrix);
//
        cblas_dgemm(CblasRowMajor,
                    CblasNoTrans,
                    CblasNoTrans,
                    given_array.rank1,
                    given_array.rank2,
                    rank1,
                    1.0,
                    array_buffer,
                    given_array.rank2,
                    data2,
                    rank2,
                    1.0,
                    given_array.data2,
                    given_array.rank2);
//
        delete[] array_buffer;
        break;
    }
}