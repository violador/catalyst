// ../src/log_file_handler/log_file_handler__report_bad_init.cpp ============================ //
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
inline void report_bad_init()
{
    std::cerr << "\n@Catalyst: fails to create "
              << manager.file_system::name()
              << " in the folder "
              << manager.file_system::parent_dir()
              << ". The program will keep running without write the file."
              << " You may or may not see the output properly." << std::endl;
};