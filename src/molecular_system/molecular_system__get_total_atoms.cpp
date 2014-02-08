// ../src/molecular_system/molecular_system__get_total_atoms.cpp ============================ //
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
#include "molecular_system.hpp"
//
//
//
unsigned int molecular_system::get_total_atoms(const std::string &input_filename)
{
//  (1) To open the input file.
//  (2) If the input file is open and ok: count the number of lines.
//  (3) To read an entire line from the input.
//  (4) To increment the counter.
//  (5) The total number of lines is the total number of atoms.
    global_log::file.write_debug_msg("molecular_system::get_total_atoms()");
    std::fstream geometry_file(input_filename.c_str(), std::fstream::in); // (1)
    switch(geometry_file.std::fstream::is_open())                         // (2)
    {
        case true:
        {
            unsigned int line_counter = 0;
            std::string line;
            while(std::getline(geometry_file, line))                      // (3)
            {
                ++line_counter;                                           // (4)
            }  
            geometry_file.std::fstream::close();
            total_atoms_ready = true;
            return line_counter;                                          // (5)
        }
        break;
        case false:
        {
            global_log::file.write("ERROR: The file system could not open the file ", 
                                   input_filename,
                                   "! This is a critical point and the program could not keep running.",
                                   " It will abort here and you may or may not see the properly output.");
            total_atoms_ready = false;
            return 0;
        }
        break;
    }
}