#include "log_file_handler.hpp"
//
//
//
log_file_handler::log_file_handler(): file_manager(NULL),
                                      log_file_ready(false),
                                      config(&global_settings::config)
{
    file_system init(config -> filename_of(option::log_file), 
                     config -> dir_path_of(option::scratch));
    file_manager = &init;
    switch(config -> state_of(option::output_mode))
    {
        case true:
        {
            switch(file_manager -> exists())
            {
                case false: open_and_init(); break;
                case  true: open(); break;
            }
        }
        break;
    }
}
//
//
//
log_file_handler::log_file_handler(settings &runtime_setup)
{
    config = &runtime_setup;
    file_system init(config -> filename_of(option::log_file), 
                     config -> dir_path_of(option::scratch));
    file_manager = &init;
    switch(config -> state_of(option::output_mode))
    {
        case false:
        {
            log_file_ready = false;
        }
        break;
        case true:
        {
            switch(file_manager -> exists())
            {
                case false: open_and_init(); break;
                case  true: open(); break;
            }
        }
        break;
    }
}
//
//
//
log_file_handler::log_file_handler(log_file_handler &given): file_manager(given.file_manager),
                                                             log_file_ready(given.log_file_ready),
                                                             config(given.config)
{
    switch(given.log_file_ready)
    {
        case true:
        this -> file_manager -> open_txt_output(this -> log_file);
        break;
    }
}
