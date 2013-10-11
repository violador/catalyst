#include "molecular_system.hpp"
//
//
//
molecular_system::molecular_system(const std::string &input_filename)
{
    settings runtime_setup;
    molecular_system(input_filename, runtime_setup);
}
//
//
//
molecular_system::molecular_system(const std::string &input_filename, settings &runtime_setup)
{
    config = &runtime_setup;
    #pragma omp parallel sections num_threads(8)
    {
        #pragma omp section
        {
            global_log::file.write_debug_msg("molecular_system::molecular_system()");
            global_log::file.write_debug_msg("molecular_system::molecular_system(): Init data from ", input_filename);
        }
        #pragma omp section
        {
            task_number = DEFAULT_TASK_NUMBER;
        }
        #pragma omp section
        {
            ab_initio_ready = false;
        }
        #pragma omp section
        {
            system_com_ready = false;
        }
        #pragma omp section
        {
            nuclear_repulsion_ready = false;
        }
        #pragma omp section
        {
            system_name = input_filename;
        }
        #pragma omp section
        {
            total_atoms_ready = false;
            total_atoms = get_total_atoms(input_filename);
            atom_types_ready = false;
            atom_positions_ready = false;
            atom_velocities_ready = false;
            read_input_file(input_filename);
        }
        #pragma omp section
        {
            charge = nuclear_repulsion = system_com_x = system_com_y = system_com_z = 0.0;
        }
    }
    report_input_reading();
}
