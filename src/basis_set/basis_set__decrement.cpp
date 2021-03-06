// ../src/basis_set/basis_set__decrement.cpp ================================================ //
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
/// @brief Moves the current iterator back.
//
/// @return None.
//
inline void operator --()
{
//
/// @note Notice that the usage of this operator after or before the
///       current object, @c --object or @c object--, works exactly
///       the same way: Moves back the current element.
//
	switch(iter > 1)
	{
		case true: --iter; break;
	}
};
//
//
//
/// @brief Moves the current iterator back.
//
/// @return None.
//
inline void operator --(int)
{
//
/// @note Notice that the usage of this operator after or before the
///       current object, @c --object or @c object--, works exactly
///       the same way: Moves back the current element.
//
	switch(iter > 1)
	{
		case true: --iter; break;
	}
};
