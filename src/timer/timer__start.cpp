// ../src/timer/timer__start.cpp ============================================================ //
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
/// @brief Starts the time elapsed measurement if not started already.
//
/// @return None.
//
/// @cite boost
//
inline void start()
{
	switch(stopped)
	{
		case true:
		stopped = false;
		++counter;
		chronometer.boost::timer::cpu_timer::start();
		break;
	}
};
