#include "molecular_system.hpp"
//
//
//
void molecular_system::read_input_file(const std::string &input_filename)
{
//  (1) To get the element type, as a string type.
//  (2) To store the element type, as an unsigned int type.
//  (3) To update the total mass.
    if(total_atoms_ready && (total_atoms > 0))
    {
        std::ifstream geometry_file(input_filename.c_str(), std::ios::in);
        if(geometry_file.is_open() && geometry_file.good() && (total_atoms > 0))
        {
            #pragma omp parallel sections num_threads(7)
            {
                #pragma omp section
                {
                    atom_type.create_array(total_atoms);
                    atom_type.set_name("Atom types");
                }
                #pragma omp section
                {
                    position_x.create_array(total_atoms);
                    position_x.set_name("x-axis");
                }
                #pragma omp section
                {
                    position_y.create_array(total_atoms);
                    position_y.set_name("y-axis");
                }
                #pragma omp section
                {
                    position_z.create_array(total_atoms);
                    position_z.set_name("z-axis");
                }
                #pragma omp section
                {
                    velocity_x.create_array(total_atoms);
                    velocity_x.set_name("x-axis");
                }
                #pragma omp section
                {
                    velocity_y.create_array(total_atoms);
                    velocity_y.set_name("y-axis");
                }
                #pragma omp section
                {
                    velocity_z.create_array(total_atoms);
                    velocity_z.set_name("z-axis");
                }
            }
            total_mass = 0.0;
            std::string element_symbol = "";
            unsigned int i = 0;
            double x = 0.0;
            double y = 0.0;
            double z = 0.0;
            periodic_table get;
            //#pragma omp parallel for private(i, x, y, z) ordered schedule(dynamic)
            for(i = 1; i <= total_atoms; i++)
            {
                geometry_file >> element_symbol;                                        // (1)
                geometry_file >> x;
                geometry_file >> y;
                geometry_file >> z;
                position_x.set(i, x);
                position_y.set(i, y);
                position_z.set(i, z);
                x = y = z = 0.0;
                geometry_file >> x;
                geometry_file >> y;
                geometry_file >> z;
                velocity_x.set(i, x);
                velocity_y.set(i, y);
                velocity_z.set(i, z);
                x = y = z = 0.0;
                atom_type.set(i, get.periodic_table::type(element_symbol));             // (2)
                //#pragma omp critical
                total_mass += get.periodic_table::mass(atom_type.get(i));               // (3)
            }
            geometry_file.close();
            atom_types_ready = true;
            atom_positions_ready = true;
            atom_velocities_ready = true;
        }
        else // if(!geometry_file.is_open() || !geometry_file.good() || !(total_atoms > 0))
        {
           // file not open! 
        }
    }
}
