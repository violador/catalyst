// ../src/periodic_table/periodic_table__init.cpp =========================================== //
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
/// @param [in] element The number of the desired chemical element.
//
/// @brief Changes the current element and update the internal data.
//
/// @return None.
//
inline void init(const unsigned int &element)
{
	current_element = element;
	update_data();
};
//
//
//
/// @param [in] element The symbol of the desired chemical element.
//
/// @brief Changes the current element and update the internal data.
//
/// @return None.
//
inline void init(const std::string &element)
{
	current_element = 0;
	do
	{
		++current_element;
		update_data();
	}
	while(element.std::string::compare(current_symbol) not_eq 0);
};
