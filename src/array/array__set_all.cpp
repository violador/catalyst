// ../src/array/array__set_all.cpp ========================================================== //
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
inline void set_all(const double &value)
{
    #pragma omp parallel sections num_threads(4)
    {
        #pragma omp section
        {
            switch(is_1d_array and (not deleted_array) and (not is_const_array))
            {
                case true:
                gsl_vector_set_all(&gsl_1d_view.vector, value);
                break;
            }
        }
        #pragma omp section
        {
            switch(is_2d_array and (not deleted_array) and (not is_const_array))
            {
                case true:
                gsl_matrix_set_all(&gsl_2d_view.matrix, value);
                break;
            }
        }
        #pragma omp section
        {
            switch(is_3d_array and (not deleted_array) and (not is_const_array))
            {
                case true:
                unsigned int i = 0, j = 0, m = 0;
                #pragma omp parallel for private(i) ordered schedule(dynamic)
                for(i = 0; i < sizeof_1st_layer; i++)
                {
                    #pragma omp parallel for private(j) ordered schedule(dynamic)
                    for(j = 0; j < sizeof_2nd_layer; j++)
                    {
                        #pragma omp parallel for private(m) ordered schedule(dynamic)
                        for(m = 0; m < sizeof_row; m++)
                        {
                            user_3d_array[i][j][m] = value;
                        }
                    }
                }
                break;
            }
        }
        #pragma omp section
        {
            switch(is_4d_array and (not deleted_array) and (not is_const_array))
            {
                case true:
                unsigned int i = 0, j = 0, m = 0, n = 0;
                #pragma omp parallel for private(i) ordered schedule(dynamic)
                for(i = 0; i < sizeof_1st_layer; i++)
                {
                    #pragma omp parallel for private(j) ordered schedule(dynamic)
                    for(j = 0; j < sizeof_2nd_layer; j++)
                    {
                        #pragma omp parallel for private(m) ordered schedule(dynamic)
                        for(m = 0; m < sizeof_row; m++)
                        {
                            #pragma omp parallel for private(n) ordered schedule(dynamic)
                            for(n = 0; n < sizeof_column; n++)
                            {
                                user_4d_array[i][j][m][n] = value;
                            }
                        }
                    }
                }
                break;
            }
        }
    } // pragma omp parallel sections num_threads(4)
}