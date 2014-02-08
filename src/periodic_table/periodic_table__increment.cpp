// ../src/periodic_table/periodic_table__increment.cpp ====================================== //
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
/// @brief Moves the current element forward.
//
/// @return None.
//
inline void operator ++()
{
//
/// @note Notice that the usage of this operator after or before the
///       current object, @c ++object or @c object++, works exactly
///       the same way: Moves forward the current element.
//
	switch(current_element < table_length)
	{
		case true:
		++current_element;
		update_data();
		break;
	}
};
//
//
//
/// @brief Moves the current element forward.
//
/// @return None.
//
inline void operator ++(int)
{
//
/// @note Notice that the usage of this operator after or before the
///       current object, @c ++object or @c object++, works exactly
///       the same way: Moves forward the current element.
//
	switch(current_element < table_length)
	{
		case true:
		++current_element;
		update_data();
		break;
	}
};
