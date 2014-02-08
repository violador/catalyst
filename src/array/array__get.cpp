// ../src/array/array__get.cpp ============================================================== //
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
inline double get(const unsigned int &i)
{
    switch(is_1d_array 
           and (not deleted_array)
           and (i >= 1)
           and (i <= sizeof_row))
    {
        case false: return 0.0; break;
        case  true: return user_1d_array[i - 1]; break;
    }
};
//
//
//
inline double get(const unsigned int &i, const unsigned int &j)
{
    switch(is_2d_array 
           and (not deleted_array)
           and (i >= 1) 
           and (j >= 1) 
           and (i <= sizeof_row) 
           and (j <= sizeof_column))
    {
        case false: return 0.0; break;
        case  true: return user_2d_array[(i - 1)*sizeof_row + (j - 1)]; break;
    }
};
//
//
//
inline double get(const unsigned int &i, const unsigned int &j, const unsigned int &m)
{
    switch(is_3d_array 
           and (not deleted_array)
           and (i >= 1)
           and (j >= 1)
           and (m >= 1)
           and (i <= sizeof_row)
           and (j <= sizeof_column)
           and (m <= sizeof_1st_layer))
    {
        case false: return 0.0; break;
        case  true: return user_3d_array[i - 1][j - 1][m - 1]; break;
    }
};
//
//
//
inline double get(const unsigned int &i, 
                  const unsigned int &j, 
                  const unsigned int &m, 
                  const unsigned int &n)
{ 
    switch(is_4d_array 
           and (not deleted_array)
           and (i >= 1)
           and (j >= 1)
           and (m >= 1)
           and (n >= 1)
           and (i <= sizeof_row)
           and (j <= sizeof_column)
           and (m <= sizeof_1st_layer)
           and (n <= sizeof_2nd_layer))
    {
        case false: return 0.0; break;
        case  true: return user_4d_array[i - 1][j - 1][m - 1][n - 1]; break;
    }
};