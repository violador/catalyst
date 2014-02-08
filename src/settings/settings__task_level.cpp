// ../src/settings/settings__task_level.cpp ================================================= //
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
/// @param [in] task The number of a given task
//
/// @brief Returns the current level of theory (its enum) for a
///        given task.
//
/// @return A non-negative integer.
//
inline unsigned int &task_level(unsigned int &task)
{
	switch(task <= total_tasks)
	{
		case false: return level_list[0]; break;
		case  true: return level_list[task - 1]; break;
	}
};
