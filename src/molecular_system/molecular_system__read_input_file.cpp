// ../src/molecular_system/molecular_system__read_input_file.cpp ============================ //
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
void molecular_system::read_input_file(const std::string &input_filename)
{
    global_log::file.write_debug_msg("molecular_system::read_input_file(): Reading from ", input_filename);
    switch(total_atoms_ready and (total_atoms > 0))
    {
        case true:
        std::fstream geometry_file(input_filename.c_str(), std::fstream::in);
        if(geometry_file.std::fstream::is_open() and geometry_file.std::fstream::good())
        {
            #pragma omp parallel sections num_threads(7)
            {
                #pragma omp section
                {
                    atom_type.array::create_array(total_atoms);
                    atom_type.array::set_name("Atom types");
                }
                #pragma omp section
                {
                    position_x.array::create_array(total_atoms);
                    position_x.array::set_name("x-axis");
                }
                #pragma omp section
                {
                    position_y.array::create_array(total_atoms);
                    position_y.array::set_name("y-axis");
                }
                #pragma omp section
                {
                    position_z.array::create_array(total_atoms);
                    position_z.array::set_name("z-axis");
                }
                #pragma omp section
                {
                    velocity_x.array::create_array(total_atoms);
                    velocity_x.array::set_name("x-axis");
                }
                #pragma omp section
                {
                    velocity_y.array::create_array(total_atoms);
                    velocity_y.array::set_name("y-axis");
                }
                #pragma omp section
                {
                    velocity_z.array::create_array(total_atoms);
                    velocity_z.array::set_name("z-axis");
                }
            }
            total_mass = 0.0;
            std::string element_symbol = "";
            unsigned int i = 0;
            double x = 0.0, y = 0.0, z = 0.0;
//
//          (1) To read the element type, as a string type.
//          (2) To read the position x-axis value.
//          (3) To read the position y-axis value.
//          (4) To read the position z-axis value.
//          (5) To read the velocity x-axis value.
//          (6) To read the velocity y-axis value.
//          (7) To read the velocity z-axis value.
//          (8) To store the element type, as an unsigned int type.
//          (9) To update the total mass.
            for(i = 1; i <= total_atoms; ++i)
            {
                geometry_file >> element_symbol;                      // (1)
                geometry_file >> x;                                   // (2)
                geometry_file >> y;                                   // (3)
                geometry_file >> z;                                   // (4)
                position_x.array::set(i, x);
                position_y.array::set(i, y);
                position_z.array::set(i, z);
                x = y = z = 0.0;
                geometry_file >> x;                                   // (5)
                geometry_file >> y;                                   // (6)
                geometry_file >> z;                                   // (7) 
                velocity_x.array::set(i, x);
                velocity_y.array::set(i, y);
                velocity_z.array::set(i, z);
                x = y = z = 0.0;
//
                periodic_table data(element_symbol);
                atom_type.array::set(i, data.periodic_table::type()); // (8)
                total_mass += data.periodic_table::mass();            // (9)
            }
//
            geometry_file.std::fstream::close();
            atom_types_ready = true;
            atom_positions_ready = true;
            atom_velocities_ready = true;
        }
        else // if(not geometry_file.is_open() or (not geometry_file.good()))
        { 
            global_log::file.write("ERROR: The file system could not open the file ",
                                   input_filename,
                                   "! This is a critical point and the program could not keep running.",
                                   " It will abort here and you may or may not see the properly output.");
            atom_types_ready = false;
            atom_positions_ready = false;
            atom_velocities_ready = false;
        }
        break;
    }
}