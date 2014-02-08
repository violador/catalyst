// ../src/settings/settings__ctrl_key.cpp =================================================== //
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
/// @param [in] state The current @c bool state of some given key.
//
/// @brief Returns the 'on' or 'off' key, according with the given @c state.
//
/// @return A string pattern.
//
inline std::string ctrl_key(const bool &state)
{
	switch(state)
	{
		case false: return tools::off_ctrl_key(); break;
		case  true: return  tools::on_ctrl_key(); break;
	}
};
