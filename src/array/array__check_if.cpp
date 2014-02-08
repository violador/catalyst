// ../src/array/array__check_if.cpp ========================================================= //
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
inline bool check_if(const unsigned int &option)
{
    switch(option)
    {
        case   option::is_positive: return is_positive();   break;
        case   option::is_negative: return is_negative();   break;
        case       option::is_null: return is_null();       break;
        case   option::is_constant: return is_const_array;  break;
        case     option::is_square: return is_square_array; break;
        case    option::is_deleted: return deleted_array;   break;
        case option::is_transposed: return is_transposed;   break;
                           default: return false;           break;
    }
};