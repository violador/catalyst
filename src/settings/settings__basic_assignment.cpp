#include "settings.hpp"
//
//
//
void settings::operator =(settings &given_config)
{
/*
    switch(given_config.total_tasks >= 1)
    {
        case false:
        {
            input_filename = new std::string[1];
            theory_level = new unsigned int[1];
            this -> output_mode_on      = given_config.output_mode_on;     
            this -> vibration_mode_on   = given_config.vibration_mode_on;
            this -> rotation_mode_on    = given_config.rotation_mode_on;
            this -> translation_mode_on = given_config.translation_mode_on;
            this -> debug_mode_on       = given_config.debug_mode_on;
            this -> highend_mode_on     = given_config.highend_mode_on;
            this -> standby_mode_on     = given_config.standby_mode_on;    
            this -> temp_files_on       = given_config.temp_files_on;
            this -> total_tasks         = given_config.total_tasks;
            this -> precision           = given_config.precision;
            this -> log_filename        = given_config.log_filename;
            this -> input_filename[0]   = given_config.input_filename[0];
            this -> scratch_dir         = given_config.scratch_dir;
            this -> work_dir            = given_config.work_dir;
            this -> in_energy_unit      = given_config.in_energy_unit;
            this -> in_length_unit      = given_config.in_length_unit;
            this -> in_time_unit        = given_config.in_time_unit;
            this -> out_energy_unit     = given_config.out_energy_unit;
            this -> out_length_unit     = given_config.out_length_unit;
            this -> out_time_unit       = given_config.out_time_unit;
            this -> scf_criteria        = given_config.scf_criteria;
            this -> theory_level[0]     = given_config.theory_level[0];
        }
        break;
        case true: 
        {
            input_filename = new std::string[given_config.total_tasks];
            theory_level = new unsigned int[given_config.total_tasks];
            #pragma omp parallel sections num_threads(2)
            {
                #pragma omp section
                {
                    unsigned int task_counter = 0;
                    #pragma omp parallel for private(task_counter) ordered schedule(dynamic)
                    for(task_counter = 1; task_counter <= given_config.total_tasks; task_counter++)
                    {
                        this -> input_filename[task_counter] = given_config.input_filename[task_counter];
                        this -> theory_level[task_counter]   = given_config.theory_level[task_counter];
                    }
                }
                #pragma omp section
                {
                    this -> output_mode_on      = given_config.output_mode_on;
                    this -> vibration_mode_on   = given_config.vibration_mode_on;
                    this -> rotation_mode_on    = given_config.rotation_mode_on;
                    this -> translation_mode_on = given_config.translation_mode_on;
                    this -> debug_mode_on       = given_config.debug_mode_on;
                    this -> highend_mode_on     = given_config.highend_mode_on;
                    this -> standby_mode_on     = given_config.standby_mode_on;
                    this -> temp_files_on       = given_config.temp_files_on;
                    this -> total_tasks         = given_config.total_tasks;
                    this -> precision           = given_config.precision;
                    this -> log_filename        = given_config.log_filename;
                    this -> scratch_dir         = given_config.scratch_dir;
                    this -> work_dir            = given_config.work_dir;
                    this -> in_energy_unit      = given_config.in_energy_unit;
                    this -> in_length_unit      = given_config.in_length_unit;
                    this -> in_time_unit        = given_config.in_time_unit;
                    this -> out_energy_unit     = given_config.out_energy_unit;
                    this -> out_length_unit     = given_config.out_length_unit;
                    this -> out_time_unit       = given_config.out_time_unit;
                    this -> scf_criteria        = given_config.scf_criteria;
                }
            }
        }
        break;
    }
*/
}
