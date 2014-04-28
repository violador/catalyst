// ../src/array/array__subtraction_assignment.cpp =========================================== //
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
void array::operator -=(const array &b)
{
//
//  Given the arrays A (the this pointer) and B: A = A - B
//
    #pragma omp parallel sections num_threads(4)
    {
        #pragma omp section
        {
            if(this -> is_1d() 
               and b.is_1d() 
               and (this -> rank1 == b.rank1)
               and (not this -> constant)
               and (not this -> is_deleted()))
            {
                cblas_daxpy(this -> rank1,
                            -1.0,
                            b.data1,
                            1,
                            this -> data1,
                            1);
            }
        }
        #pragma omp section
        {
            if(this -> is_2d() 
               and b.is_2d() 
               and (this -> rank1 == b.rank1) 
               and (this -> rank2 == b.rank2)
               and (not this -> constant)
               and (not this -> is_deleted()))
            {
                cblas_daxpy((this -> rank1)*(this -> rank2),
                            -1.0,
                            b.data2,
                            1,
                            this -> data2,
                            1);
            }
        }
        #pragma omp section
        {
            if(this -> is_3d() 
               and b.is_3d() 
               and (this -> rank1 == b.rank1) 
               and (this -> rank2 == b.rank2) 
               and (this -> rank3 == b.rank3)
               and (not this -> constant)
               and (not this -> is_deleted()))
            {
                unsigned int i = 0, j = 0, m = 0;
                #pragma omp parallel for private(i) ordered schedule(dynamic)
                for(i = 0; i < this -> rank1; i++)
                {
                    #pragma omp parallel for private(j) ordered schedule(dynamic)
                    for(j = 0; j < this -> rank2; j++)
                    {
                        #pragma omp parallel for private(m) ordered schedule(dynamic)
                        for(m = 0; m < this -> rank3; m++)
                        {
                            this -> data3[i][j][m] = this -> data3[i][j][m] 
                                                           - b.data3[i][j][m];
                        }
                    }
                }
            }
        }
        #pragma omp section
        {
            if(this -> is_4d()    
               and b.is_4d() 
               and (this -> rank1 == b.rank1) 
               and (this -> rank2 == b.rank2) 
               and (this -> rank3 == b.rank3)
               and (this -> rank4 == b.rank4)
               and (not this -> constant)
               and (not this -> is_deleted()))
            {
                unsigned int i = 0, j = 0, m = 0, n = 0;
                #pragma omp parallel for private(i) ordered schedule(dynamic)
                for(i = 0; i < this -> rank1; i++)
                {
                    #pragma omp parallel for private(j) ordered schedule(dynamic)
                    for(j = 0; j < this -> rank2; j++)
                    {
                        #pragma omp parallel for private(m) ordered schedule(dynamic)
                        for(m = 0; m < this -> rank3; m++)
                        {
                            #pragma omp parallel for private(n) ordered schedule(dynamic)
                            for(n = 0; n < this -> rank4; n++)
                            {
                                 this -> data4[i][j][m][n] = this -> data4[i][j][m][n] 
                                                                   - b.data4[i][j][m][n];
                            }
                        }
                    }
                }
            }
        }
    } // pragma omp parallel sections num_threads(4)
}