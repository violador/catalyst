// ../src/array/array__delete_4d_array.cpp ================================================== //
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
// ../src/array/array__delete_4d_array.cpp -------------------------------------------------- //
//
//  This file is part of Catalyst lib.
//
//  Catalyst lib is free software: you can redistribute it and/or modify it under the terms 
//  of the GNU General Public License as published by the Free Software Foundation, either 
//  version 3 of the License, or (at your option) any later version.
//
//  Catalyst lib is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
//  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
//  See the GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License along with Catalyst lib. 
//  If not, see <http://www.gnu.org/licenses/>.
//
// ------------------------------------------------------------------------------------------ //
//
//
//
/// @author Humberto Jr.
//
/// @date 07/2013
//
/// @return None. Deallocates the current memory for a 4D array.
//
/// @cite
//
inline void delete_4d_array()
{
    unsigned int i = 0;
    #pragma omp parallel for private(i) ordered schedule(dynamic)
    for(i = 0; i < sizeof_row; ++i)             
    {
        unsigned int j = 0;
        #pragma omp parallel for private(j) ordered schedule(dynamic)
        for(j = 0; j < sizeof_column; ++j)
        {
            unsigned int m = 0;
            #pragma omp parallel for private(m) ordered schedule(dynamic)
            for(m = 0; m < sizeof_column; ++m)
            {
                delete[] user_4d_array[i][j][m];
            }
            delete[] user_4d_array[i][j];
        }
        delete[] user_4d_array[i];
    }
    delete[] user_4d_array;
};