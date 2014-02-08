// ../src/periodic_table/periodic_table__type.cpp =========================================== //
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
inline unsigned int type(const std::string &given_symbol)
{
/*
    unsigned int i = 0, type_found = 0;
    #pragma omp parallel for private(i) ordered schedule(dynamic)
    for(i = 1; i <= total_elements; ++i)
    {
        switch((bool) given_symbol.std::string::compare(symbol(i)))
        {
            case false: type_found = i; break;
        }
    }
    return type_found;
*/
    return 0;
}
//
//
//
/// @brief Returns the number of the current element.
//
/// @return A non-negative integer.
//
inline unsigned int &type()
{
	return current_element;
};
