// ../src/array/array__basic_assignment.cpp ================================================= //
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
void array::operator =(const array &b)
{
//
//  Given the arrays A (the this pointer) and B: A = B
//
    #pragma omp parallel sections num_threads(4)
    {
        #pragma omp section
        {
           switch(this -> is_1d_array              // To check the A array type. 
                  and b.is_1d_array                // To check the B array type.
                  and (not this -> is_const_array) // To check if A has permision to be rewritten.
                  and (not this -> deleted_array)) // To check if A is not a deleted array.
            {
                case true:
                resize_array(b.sizeof_row);
                gsl_vector_memcpy(&this -> gsl_1d_view.vector, &b.gsl_1d_view.vector);
                break;
            }
        }
        #pragma omp section
        {
            switch(this -> is_2d_array              // To check the A array type. 
                   and b.is_2d_array                // To check the B array type.
                   and (not this -> is_const_array) // To check if A has permision to be rewritten.
                   and (not this -> deleted_array)) // To check if A is not a deleted array.
            {
                case true:
                resize_array(b.sizeof_row, b.sizeof_column);
                gsl_matrix_memcpy(&this -> gsl_2d_view.matrix, &b.gsl_2d_view.matrix);
                break;
            }
        }
        #pragma omp section
        {
            switch(this -> is_3d_array              // To check the A array type.
                   and b.is_3d_array                // To check the B array type.
                   and (not this -> is_const_array) // To check if A has permision to be rewritten.
                   and (not this -> deleted_array)) // To check if A is not a deleted array.
            {
                case true:
                resize_array(b.sizeof_row, b.sizeof_column, b.sizeof_1st_layer);
                unsigned int i = 0, j = 0, m = 0;
                #pragma omp parallel for private(i) ordered schedule(dynamic)
                for(i = 0; i < sizeof_row; ++i)
                {
                    #pragma omp parallel for private(j) ordered schedule(dynamic)
                    for(j = 0; j < sizeof_column; ++j)
                    {
                        #pragma omp parallel for private(m) ordered schedule(dynamic)
                        for(m = 0; m < sizeof_1st_layer; ++m)
                        {
                            this -> user_3d_array[i][j][m] = b.user_3d_array[i][j][m];
                        }
                    }
                }
                break;
            }
        }
        #pragma omp section
        {
            switch(this -> is_4d_array              // To check the A array type.
                   and b.is_4d_array                // To check the B array type.
                   and (not this -> is_const_array) // To check if A has permision to be rewritten.
                   and (not this -> deleted_array)) // To check if A is not a deleted array.
            {
                case true:
                resize_array(b.sizeof_row, 
                             b.sizeof_column, 
                             b.sizeof_1st_layer, 
                             b.sizeof_2nd_layer);
                unsigned int i = 0, j = 0, m = 0, n = 0;
                #pragma omp parallel for private(i) ordered schedule(dynamic)
                for(i = 0; i < sizeof_row; ++i)
                {
                    #pragma omp parallel for private(j) ordered schedule(dynamic)
                    for(j = 0; j < sizeof_column; ++j)
                    {
                        #pragma omp parallel for private(m) ordered schedule(dynamic)
                        for(m = 0; m < sizeof_1st_layer; ++m)
                        {
                            #pragma omp parallel for private(n) ordered schedule(dynamic)
                            for(n = 0; n < sizeof_2nd_layer; ++n)
                            {
                                this -> user_4d_array[i][j][m][n] = b.user_4d_array[i][j][m][n];
                            }
                        }
                    }
                }
                break;
            }
        }
    } // pragma omp parallel sections num_threads(4)
}