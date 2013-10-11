#include "log_file_handler.hpp"
//
//
//
log_file_handler::log_file_handler()
{
    log_file_ready = false;
}
//
//
//
log_file_handler::log_file_handler(settings &runtime_setup)
{
    config = &runtime_setup;
    file_system init_file(config -> filename_of(LOG_FILE), config -> dir_path_of(SCRATCH));
    file_manager = &init_file;
    if(config -> state_of(OUTPUT_MODE))
    {
        if(file_manager -> exists())
        {
            file_manager -> open_txt_output(log_file);
            file_manager -> open_txt_output(output);
            file_manager -> is_open()? log_file_ready = true : log_file_ready = false;
        }
        else // if(not file_manager -> exists())
        {
            file_manager -> open_txt_output(log_file);
            if(file_manager -> is_open())
            {
                log_file_ready = true;
                init_log_file();
                file_manager -> open_txt_output(output);
            }
            else
            {
//
                std::cout << "\n@Catalyst: fails to create "
                          << config -> filename_of(LOG_FILE)
                          << " in the folder "
                          << file_manager -> parent_dir()
                          << ". The program will keep running without write the file. You may or may not see the output properly."
                          << std::endl;
//
                log_file_ready = false;
            }
        }
    }
    else
    {
        log_file_ready = false;
    }
}
//
//
//
log_file_handler::log_file_handler(log_file_handler &given_log_file)
{
    #pragma omp parallel sections num_threads(3)
    {
        #pragma omp section
        {
            this -> config = given_log_file.config;
        }
        #pragma omp section
        {
            this -> log_file_ready = given_log_file.log_file_ready;
        }
        #pragma omp section
        {
            this -> file_manager = given_log_file.file_manager;
            if(given_log_file.log_file_ready)
            {
                this -> file_manager -> open_txt_output(this -> log_file);
                this -> file_manager -> open_txt_output(this -> output);
            }
        } 
    }
}
