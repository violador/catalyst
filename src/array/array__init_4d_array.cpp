// ../src/array/array__init_4d_array.cpp ==================================================== //
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
inline void init_4d_array(const unsigned int &row_size, 
                          const unsigned int &column_size, 
                          const unsigned int &layer1_size,
                          const unsigned int &layer2_size)
{
    unsigned int i = 0, j = 0, m = 0, n = 0;
    user_4d_array = new double ***[row_size];
    #pragma omp parallel for private(i) ordered schedule(dynamic)
    for(i = 0; i < row_size; ++i)
    {
        user_4d_array[i] = new double **[column_size];
        #pragma omp parallel for private(j) ordered schedule(dynamic)
        for(j = 0; j < column_size; ++j)
        {
            user_4d_array[i][j] = new double *[layer1_size];
            #pragma omp parallel for private(m) ordered schedule(dynamic)
            for(m = 0; m < layer1_size; ++m)
            {
                user_4d_array[i][j][m] = new double[layer2_size];
            }
        }
    }
    #pragma omp parallel for private(i) ordered schedule(dynamic)
    for(i = 0; i < row_size; ++i)
    {
        #pragma omp parallel for private(j) ordered schedule(dynamic)
        for(j = 0; j < column_size; ++j)
        {
            #pragma omp parallel for private(m) ordered schedule(dynamic)
            for(m = 0; m < layer1_size; ++m)
            {
                #pragma omp parallel for private(n) ordered schedule(dynamic)
                for(n = 0; n < layer2_size; ++n)
                {
                    user_4d_array[i][j][m][n] = 0.0;
                }
            }
        }
    }
};