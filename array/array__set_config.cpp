//
//
//
inline void set_config(settings &runtime_setup, log_file_handler &file)
{
    #pragma omp parallel sections num_threads(3)
    {
        #pragma omp section
        {
            config = &runtime_setup;
        }
        #pragma omp section
        {
            log_file = &file;
        }
        #pragma omp section
        {
            setup_ready = true;
        }
    }
    //config -> state_of(HIGHEND_MODE)? lowend_mode_on = false : lowend_mode_on = true;
};
