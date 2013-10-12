#include "molecular_system.hpp"
//
//
//
void molecular_system::read_input_file(const std::string &input_filename)
{
    if(total_atoms_ready and (total_atoms > 0))
    {
        std::ifstream geometry_file(input_filename.c_str(), std::ios::in);
        if(geometry_file.is_open() and geometry_file.good() and (total_atoms > 0))
        {
            #pragma omp parallel sections num_threads(7)
            {
                #pragma omp section
                {
                    atom_type.array::create_array(total_atoms);
                    atom_type.array::set_name("Atom types");
                    atom_type.array::set_config(*config);
                }
                #pragma omp section
                {
                    position_x.array::create_array(total_atoms);
                    position_x.array::set_name("x-axis");
                    position_x.array::set_config(*config);
                }
                #pragma omp section
                {
                    position_y.array::create_array(total_atoms);
                    position_y.array::set_name("y-axis");
                    position_y.array::set_config(*config);
                }
                #pragma omp section
                {
                    position_z.array::create_array(total_atoms);
                    position_z.array::set_name("z-axis");
                    position_z.array::set_config(*config);
                }
                #pragma omp section
                {
                    velocity_x.array::create_array(total_atoms);
                    velocity_x.array::set_name("x-axis");
                    velocity_x.array::set_config(*config);
                }
                #pragma omp section
                {
                    velocity_y.array::create_array(total_atoms);
                    velocity_y.array::set_name("y-axis");
                    velocity_y.array::set_config(*config);
                }
                #pragma omp section
                {
                    velocity_z.array::create_array(total_atoms);
                    velocity_z.array::set_name("z-axis");
                    velocity_z.array::set_config(*config);
                }
            }
            total_mass = 0.0;
            std::string element_symbol = "";
            unsigned int i = 0;
            double x = 0.0, y = 0.0, z = 0.0;
            periodic_table get;
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
            for(i = 1; i <= total_atoms; i++)
            {
                geometry_file >> element_symbol;                                   // (1)
                geometry_file >> x;                                                // (2)
                geometry_file >> y;                                                // (3)
                geometry_file >> z;                                                // (4)
                position_x.array::set(i, x);
                position_y.array::set(i, y);
                position_z.array::set(i, z);
                x = y = z = 0.0;
                geometry_file >> x;                                                // (5)
                geometry_file >> y;                                                // (6)
                geometry_file >> z;                                                // (7) 
                velocity_x.array::set(i, x);
                velocity_y.array::set(i, y);
                velocity_z.array::set(i, z);
                x = y = z = 0.0;
                atom_type.array::set(i, get.periodic_table::type(element_symbol)); // (8)
                total_mass += get.periodic_table::mass(atom_type.array::get(i));   // (9)
            }
//
            geometry_file.close();
            atom_types_ready = true;
            atom_positions_ready = true;
            atom_velocities_ready = true;
        }
        else // if(not geometry_file.is_open() or (not geometry_file.good()) or (not total_atoms > 0))
        { 
            std::cout << "\nfile not opened." << std::endl;
        }
    }
}