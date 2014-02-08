// ../src/basis_set/basis_set__function_call.cpp ============================================ //
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
/// @brief Defines a new iterator value if given in the
///        valid range between 1 and the current set size.
//
/// @return None.
//
inline double &operator ()(const unsigned int &new_iter)
{
	switch(new_iter <= current_set_size)
	{
		case true: iter = new_iter; break;
	}
};
