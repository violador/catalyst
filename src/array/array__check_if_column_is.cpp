// ../src/array/array__check_if_column_is.cpp =============================================== //
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
bool array::check_if_column_is(const unsigned int &option, const unsigned int &j)
{
    if(is_2d())
    {
        if((j > 0) && (j <= rank2))
        {
            switch(option)
            {
            case 1:
            { 
                gsl_vector_const_view array_column = gsl_matrix_const_row(&gsl_2d_view.matrix, j - 1);
                return (bool) gsl_vector_ispos(&array_column.vector);
            } 
            break;
            case 2:
            {
                gsl_vector_const_view array_column = gsl_matrix_const_row(&gsl_2d_view.matrix, j - 1);
                return (bool) gsl_vector_isneg(&array_column.vector);
            }
            break;
            default: return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}