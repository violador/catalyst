// ../src/file_system/file_system__open_bin_output.cpp ====================================== //
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
void file_system::open_bin_output(std::fstream &file)
{
    std::string temp_filename = root_dir() + relative_dir();
//
    file.std::fstream::open(temp_filename.std::string::c_str(), 
                            std::fstream::out | std::ios::binary | std::ios::app);
//
    switch(file.std::fstream::is_open() and file.std::fstream::good())
    {
        case true: stream_ready = true; break;
    }
}
//
//
//
void file_system::open_bin_output(FILE *file)
{
    std::string temp_filename = root_dir() + relative_dir();
//
    file = fopen(temp_filename.std::string::c_str(), "w");
//
    switch(file not_eq NULL)
    {
        case true: stream_ready = true; break;
    }
}
//
//
//
void file_system::open_bin_output()
{
    std::string temp_filename = root_dir() + relative_dir();
//
    output_file.std::fstream::open(temp_filename.std::string::c_str(), 
                                   std::fstream::out | std::ios::binary | std::ios::app);
//
    switch(output_file.std::fstream::is_open() and output_file.std::fstream::good())
    {
        case true: stream_ready = true; break;
    }
}