// ../src/file_system/file_system__init.cpp ================================================= //
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
inline void init(const std::string &given_pathname,
                 const std::string &given_filename) 
{
    #pragma omp parallel sections num_threads(2)
    {
        #pragma omp section
        {
            input = init_file(given_filename, given_pathname);
        }
        #pragma omp section
        {
            disk_info = init_path(given_pathname);
        }
    }
    update();
};