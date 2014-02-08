// ../src/array/array__is_null.cpp ========================================================== //
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
// ../src/array/array__is_null.cpp ---------------------------------------------------------- //
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
#include "array.hpp"
//
//
//
/// @author Humberto Jr.
//
/// @date 07/2013
//
/// @return @c true if the current array is null and 
///         @c false otherwise. 
//
/// @cite
//
bool array::is_null()
{
//
/// @note Notice that this function is valid for non-deleted 
///       arrays only. 
//
/// @warning The current functions is not yet implemented 
///          for 3D and 4D arrays.
//
    bool aux;
    #pragma omp parallel sections num_threads(4)
    {
        #pragma omp section
        {
            switch(is_1d_array and (not deleted_array))
            {
                case true:
                aux = (bool) gsl_vector_isnull(&gsl_1d_view.vector);
                break;
            }
        }
        #pragma omp section
        {
            switch(is_2d_array and (not deleted_array))
            {
                case true:
                aux = (bool) gsl_matrix_isnull(&gsl_2d_view.matrix);
                break;
            }
        }
        #pragma omp section
        {
            switch(is_3d_array and (not deleted_array))
            {
                case true:
                aux = false;
                break;
            }
        }
        #pragma omp section
        {
            switch(is_4d_array and (not deleted_array))
            {
                case true:
                aux = false;
                break;
            }
        }
    }
    return aux;
} 