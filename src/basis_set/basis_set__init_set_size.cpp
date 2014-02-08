// ../src/basis_set/basis_set__init_set_size.cpp ============================================ //
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
/// @brief Uses the @c current_level to decide the type of basis
///        set to have its size checked.
//
/// @return A non-negative integer.
//
inline const unsigned int init_set_size()
{
	switch(current_level)
	{
		case basis::STO_1G: return 0; break;
		case basis::STO_2G: return 0; break;
		case basis::STO_3G: return check_sto3g_size(); break;
		case basis::STO_6G: return 0; break;
				   default: return 0; break;
	}
};
