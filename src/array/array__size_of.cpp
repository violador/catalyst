// ../src/array/array__size_of.cpp ========================================================== //
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
inline unsigned int size_of_row()
{
    switch(not is_deleted())
    {
        case false: return 0; break;
        case  true: return rank1; break;
    }
};
//
//
//
inline unsigned int size_of_column()
{
    switch(not is_deleted())
    {
        case false: return 0; break;
        case  true: return rank2; break;
    }
};
//
//
//
inline unsigned int size_of_1st_layer()
{
    switch(not is_deleted())
    {
        case false: return 0; break;
        case  true: return rank3; break;
    }
};
//
//
//
inline unsigned int size_of_2nd_layer()
{
    switch(not is_deleted())
    {
        case false: return 0; break;
        case  true: return rank4; break;
    }
};