// ../src/array/array__my_size.cpp ========================================================== //
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
inline double my_size()
{
    if(is_1d_array)
    {
        return sizeof(*this)*BYTE_TO_KILOBYTE 
               + sizeof(user_1d_array[0]*sizeof_row)*BYTE_TO_KILOBYTE;
    }
    else if(is_2d_array)
    {
        return sizeof(*this)*BYTE_TO_KILOBYTE 
               + sizeof(user_2d_array[0]*sizeof_row*sizeof_column)*BYTE_TO_KILOBYTE;
    }
    else if(is_3d_array)
    {
        return sizeof(*this)*BYTE_TO_KILOBYTE 
               + sizeof(user_3d_array)*BYTE_TO_KILOBYTE;
    }
    else if(is_4d_array)
    {
        return sizeof(*this)*BYTE_TO_KILOBYTE 
               + sizeof(user_4d_array)*BYTE_TO_KILOBYTE;
    }
    else
    {
        return sizeof(*this)*BYTE_TO_KILOBYTE;
    }
};