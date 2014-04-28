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
    switch(is_1d() 
           and (not is_deleted())
           and (i >= 1)
           and (i <= rank1))
    {
        case false: return 0.0; break;
        case  true: return data1[i - 1]; break;
    }
};
//
//
//
inline double get(const unsigned int &i, const unsigned int &j)
{
    switch(is_2d() 
           and (not is_deleted())
           and (i >= 1) 
           and (j >= 1) 
           and (i <= rank1) 
           and (j <= rank2))
    {
        case false: return 0.0; break;
        case  true: return data2[(i - 1)*rank1 + (j - 1)]; break;
    }
};
//
//
//
inline double get(const unsigned int &i, const unsigned int &j, const unsigned int &m)
{
    switch(is_3d() 
           and (not is_deleted())
           and (i >= 1)
           and (j >= 1)
           and (m >= 1)
           and (i <= rank1)
           and (j <= rank2)
           and (m <= rank3))
    {
        case false: return 0.0; break;
        case  true: return data3[i - 1][j - 1][m - 1]; break;
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
    switch(is_4d() 
           and (not is_deleted())
           and (i >= 1)
           and (j >= 1)
           and (m >= 1)
           and (n >= 1)
           and (i <= rank1)
           and (j <= rank2)
           and (m <= rank3)
           and (n <= rank4))
    {
        case false: return 0.0; break;
        case  true: return data4[i - 1][j - 1][m - 1][n - 1]; break;
    }
};