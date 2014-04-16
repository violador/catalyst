#include "log_file_handler.hpp"
//
//
//
log_file_handler::log_file_handler(): log_file_ready(false),
                                      config(&global_settings::config)
{
    manager.file_system::init(config -> work_dir(), config -> log_file());
    switch(config -> output_mode())
    {
        case true:
        switch(manager.file_system::exists())
        {
            case false: open_and_init(); break;
            case  true: open(); break;
        }
        break;
    }
}
//
//
//
log_file_handler::log_file_handler(settings &runtime_setup): log_file_ready(false),
                                                             config(&runtime_setup)
{
    manager.file_system::init(config -> work_dir(), config -> log_file());
    switch(config -> output_mode())
    {
        case true:
        switch(manager.file_system::exists())
        {
            case false: open_and_init(); break;
            case  true: open(); break;
        }
        break;
    }
}
//
//
//
log_file_handler::log_file_handler(log_file_handler &given): manager(given.manager),
                                                             log_file_ready(given.log_file_ready),
                                                             config(&global_settings::config)
{
    switch(given.log_file_ready)
    {
        case true:
        this -> manager.file_system::open_txt_output(this -> log_file);
        break;
    }
}
