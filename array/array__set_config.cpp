//
//
//
inline void set_config(settings &runtime_setup)
{
    #pragma omp parallel sections num_threads(3)
    {
        #pragma omp section
        {
            runtime_setup.settings::state_of(HIGHEND_MODE)? lowend_mode_on = false : lowend_mode_on = true;
        }
        #pragma omp section
        {
            config = &runtime_setup;
        }
        #pragma omp section
        {
            setup_ready = true;
        }
    }
};
