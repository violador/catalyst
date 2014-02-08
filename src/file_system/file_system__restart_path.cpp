// ../src/file_system/file_system__restart_path.cpp ========================================= //
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
/// @brief Changes the current path and updates the internal data.
//
/// @return None.
//
/// @cite boost_filesystem
//
void inline restart_path(const std::string &given_pathname)
{
	input = init_path(given_pathname);
	#pragma omp parallel sections num_threads(8)
	{
		#pragma omp section
		{
			filename = path.boost::filesystem::path::filename();
		}
		#pragma omp section
		{
			root_path = path.boost::filesystem::path::root_path();
		}
		#pragma omp section
		{
			parent_path = path.boost::filesystem::path::parent_path();
		}
		#pragma omp section
		{
			relative_path = path.boost::filesystem::path::relative_path();
		}
		#pragma omp section
		{
			file_extension = path.boost::filesystem::path::extension();
		}
		#pragma omp section
		{
			file_status = boost::filesystem::status(file);
		}
		#pragma omp section
		{
			path_status = boost::filesystem::status(path);
		}
		#pragma omp section
		{
			disk_space = boost::filesystem::space(path);
		}
	}
};
