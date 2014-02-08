// ../src/scf/scf__check_mo_type.cpp ======================================================== //
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
inline std::string check_mo_type(const unsigned int &mo_number) 
{
    switch((mo_number >= 1) and (mo_number <= f_eigenvectors.array::size_of_row()))
    {
        case false:
        {
            return "";
        }
        break;
        case true:
        {
            switch(f_eigenvectors.array::check_if_column_is(IS_POSITIVE, mo_number)
                   or f_eigenvectors.array::check_if_column_is(IS_NEGATIVE, mo_number))
            {
               case false: return "antibonding"; break;
               case  true: return "bonding";     break;
            }
        }
        break;
    }
};