// ../src/file_system/file_system__constructor.cpp ========================================== //
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
file_system::file_system(): input(init_file()),
							disk_info(init_path()),
							filename(file.boost::filesystem::path::filename()),
							root_path(file.boost::filesystem::path::root_path()),
							parent_path(file.boost::filesystem::path::parent_path()),
							relative_path(file.boost::filesystem::path::relative_path()),
							file_extension(file.boost::filesystem::path::extension()),
							file_status(boost::filesystem::status(file)),
							path_status(boost::filesystem::status(path)),
							disk_space(boost::filesystem::space(path)),
							stream_ready(false)
{
// Empty constructor.
}
//
//
//
file_system::file_system(const std::string &given_pathname,
                         const std::string &given_filename): input(init_file(given_filename, given_pathname)),
															 disk_info(init_path(given_pathname)),
															 filename(file.boost::filesystem::path::filename()),
															 root_path(file.boost::filesystem::path::root_path()),
															 parent_path(file.boost::filesystem::path::parent_path()),
															 relative_path(file.boost::filesystem::path::relative_path()),
															 file_extension(file.boost::filesystem::path::extension()),
															 file_status(boost::filesystem::status(file)),
															 path_status(boost::filesystem::status(path)),
															 disk_space(boost::filesystem::space(path)),
															 stream_ready(false)
{
// Empty constructor.
}
//
//
//
file_system::file_system(const file_system &input): input(input.input),
													disk_info(input.disk_info),
													filename(input.filename),
													root_path(input.root_path),
													parent_path(input.parent_path),
													relative_path(input.relative_path),
													file_extension(input.file_extension),
													file_status(input.file_status),
													path_status(input.path_status),
													disk_space(input.disk_space),
													stream_ready(false)
{
// Empty constructor.
}
