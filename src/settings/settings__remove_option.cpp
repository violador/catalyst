// ../src/settings/settings__remove_option.cpp ============================================== //
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
/// @brief A help function that changes a given @c line from the config file,
///        removing the @c option part. What remains should be the key. The
///        pattern used is @c "option = key".
//
/// @return None.
//
inline void remove_option(std::string &line,
						  const std::string &option)
{
//
/// @warning The content of the given @c line will be modified.
//
	line.std::string::erase(0, tools::pattern_length(option));
};
