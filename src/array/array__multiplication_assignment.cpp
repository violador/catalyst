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
            if(this -> is_2d()                         // To check the A array type.
               and b.is_1d()                           // To check the B array type.
               and (this -> rank2 == b.rank1) // To check if A column size fits the B row size.
               and (not this -> constant)            // To check if A has permision to be rewritten.
               and (not this -> is_deleted()))            // To check if A is not a deleted array.
            {
                double *array_buffer = new double[(this -> rank1)*(this -> rank2)];
                memcpy(array_buffer,
                       this -> data2,
                       (this -> rank1)*(this -> rank2)*sizeof this -> data2[0]);
                resize(this -> rank1, 1);
//
                cblas_dgemv(CblasRowMajor,
                            CblasNoTrans,
                            this -> rank1,
                            this -> rank2,
                            1.0,
                            array_buffer,
                            1,
                            b.data1,
                            1,
                            1.0,
                            data2,
                            1);
//
                delete[] array_buffer;
            }
        }
        #pragma omp section
        {
            if(this -> is_2d()                         // To check the A array type.
               and b.is_2d()                           // To check the B array type.
               and (this -> rank2 == b.rank1) // To check if A column size fits the B row size.
               and (not this -> constant)            // To check if A has permision to be rewritten.
               and (not this -> is_deleted()))            // To check if A is not a deleted array.
            {
                double *array_buffer = new double[(this -> rank1)*(this -> rank2)];
                memcpy(array_buffer,
                       this -> data2,
                       (this -> rank1)*(this -> rank2)*sizeof this -> data2[0]);
                resize(this -> rank1, b.rank2);
//
                cblas_dgemm(CblasRowMajor,
                            CblasNoTrans,
                            CblasNoTrans,
                            this -> rank1,
                            b.rank2,
                            this -> rank2,
                            1.0,
                            array_buffer,
                            this -> rank2,
                            b.data2,
                            b.rank2,
                            1.0,
                            this -> data2,
                            this -> rank2);
//
                delete[] array_buffer;
            }
        }
    } // #pragma omp parallel sections num_threads(2)
}
