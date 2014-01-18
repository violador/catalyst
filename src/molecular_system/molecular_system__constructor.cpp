#include "molecular_system.hpp"
//
//
//
molecular_system::molecular_system(const std::string &input_filename)
{
//
    constructor_time.timer::start();
//
    config = &global_settings::config;
    #pragma omp parallel sections num_threads(8)
    {
        #pragma omp section
        {
            global_log::file.write_debug_msg("molecular_system::molecular_system(): Init data from ", 
                                             input_filename);
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
            input.file_system::init(config -> work_dir(), input_filename);
            switch(input.file_system::exists())
            {
                case false:
                {
                    total_atoms_ready = false;
                    atom_types_ready = false;
                    atom_positions_ready = false;
                    atom_velocities_ready = false;
                }
                break;
                case true:
                {
                    total_atoms = get_total_atoms(input.file_system::full_name());
                    read_input_file(input.file_system::full_name());
                }
                break;
            }
        }
        #pragma omp section
        {
            charge = nuclear_repulsion = system_com_x = system_com_y = system_com_z = 0.0;
        }
    }
    report_input_reading();
//
    constructor_time.timer::stop();
//
}
//
//
//
molecular_system::molecular_system(const unsigned int &given_task)
{
    #pragma omp parallel sections num_threads(3)
    {
        #pragma omp section
        {
            task_number = given_task;
        }
        #pragma omp section
        {
            config = &global_settings::config;
        }
        #pragma omp section
        {
            input.file_system::init(global_settings::config.work_dir(),
                                    global_settings::config.input_filename(task_number));
        }
    }
//
    constructor_time.timer::start();
//
    #pragma omp parallel sections num_threads(7)
    {
        #pragma omp section
        {
            global_log::file.write_debug_msg("molecular_system::molecular_system(): Init data from ", 
                                             input.file_system::full_name());
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
            system_name = input.file_system::name();
        }
        #pragma omp section
        {
            switch(input.file_system::exists())
            {
                case false:
                {
                    total_atoms_ready = false;
                    atom_types_ready = false;
                    atom_positions_ready = false;
                    atom_velocities_ready = false;
                }
                break;
                case true:
                {
                    total_atoms = get_total_atoms(input.file_system::full_name());
                    read_input_file(input.file_system::full_name());
                }
                break;
            }
        }
        #pragma omp section
        {
            charge = nuclear_repulsion = system_com_x = system_com_y = system_com_z = 0.0;
        }
    }
    report_input_reading();
//
    constructor_time.timer::stop();
//
}
