// ../src/file_system/file_system__basic_assignment.cpp ===================================== //
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
#include "file_system.hpp"
//
//
//
/// @param [in] input A @c file_system object previously declared.
//
/// @brief Copy the internal members of the given @c input to the
///        current one.
//
/// @return None.
//
/// @cite boost_filesystem
//
void file_system::operator =(const file_system &input)
{
	#pragma omp parallel sections num_threads(9)
	{
		#pragma omp section
		{
			switch(this -> stream_ready)
			{
				case true: close(); break;
			}
		}
		#pragma omp section
		{
			this -> filename = input.filename;
		}
		#pragma omp section
		{
			this -> root_path = input.root_path;
		}
		#pragma omp section
		{
			this -> parent_path = input.parent_path;
		}
		#pragma omp section
		{
			this -> relative_path = input.relative_path;
		}
		#pragma omp section
		{
			this -> file_extension = input.file_extension;
		}
		#pragma omp section
		{
			this -> file_status = input.file_status;
		}
		#pragma omp section
		{
			this -> path_status = input.path_status;
		}
		#pragma omp section
		{
			this -> disk_space = input.disk_space;
		}
	}
}
