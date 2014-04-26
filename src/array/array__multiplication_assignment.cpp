// ../src/array/array__multiplication_assignment.cpp ======================================== //
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
void array::operator *=(const array &b)
{
//
//  Given the arrays A (the this pointer) and B: A = A*B
//
    #pragma omp parallel sections num_threads(2)
    {
        #pragma omp section
        {
            if(this -> is_2d_array                         // To check the A array type.
               and b.is_1d_array                           // To check the B array type.
               and (this -> sizeof_column == b.sizeof_row) // To check if A column size fits the B row size.
               and (not this -> is_const_array)            // To check if A has permision to be rewritten.
               and (not this -> deleted_array))            // To check if A is not a deleted array.
            {
                double *array_buffer = new double[(this -> sizeof_row)*(this -> sizeof_column)];
                memcpy(array_buffer,
                       this -> user_2d_array,
                       (this -> sizeof_row)*(this -> sizeof_column)*sizeof this -> user_2d_array[0]);
                resize(this -> sizeof_row, 1);
//
                cblas_dgemv(CblasRowMajor,
                            CblasNoTrans,
                            this -> sizeof_row,
                            this -> sizeof_column,
                            1.0,
                            array_buffer,
                            1,
                            b.user_1d_array,
                            1,
                            1.0,
                            user_2d_array,
                            1);
//
                delete[] array_buffer;
            }
        }
        #pragma omp section
        {
            if(this -> is_2d_array                         // To check the A array type.
               and b.is_2d_array                           // To check the B array type.
               and (this -> sizeof_column == b.sizeof_row) // To check if A column size fits the B row size.
               and (not this -> is_const_array)            // To check if A has permision to be rewritten.
               and (not this -> deleted_array))            // To check if A is not a deleted array.
            {
                double *array_buffer = new double[(this -> sizeof_row)*(this -> sizeof_column)];
                memcpy(array_buffer,
                       this -> user_2d_array,
                       (this -> sizeof_row)*(this -> sizeof_column)*sizeof this -> user_2d_array[0]);
                resize(this -> sizeof_row, b.sizeof_column);
//
                cblas_dgemm(CblasRowMajor,
                            CblasNoTrans,
                            CblasNoTrans,
                            this -> sizeof_row,
                            b.sizeof_column,
                            this -> sizeof_column,
                            1.0,
                            array_buffer,
                            this -> sizeof_column,
                            b.user_2d_array,
                            b.sizeof_column,
                            1.0,
                            this -> user_2d_array,
                            this -> sizeof_column);
//
                delete[] array_buffer;
            }
        }
    } // #pragma omp parallel sections num_threads(2)
}
