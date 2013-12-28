//
//
//
inline void operator =(const timer &given_timer)
{
    #pragma omp parallel sections num_threads(7)
    {
        #pragma omp section
        {
            this -> config = given_timer.config;
        }
        #pragma omp section
        {
            this -> wall_time = given_timer.wall_time;
        }
        #pragma omp section
        {
            this -> system_time = given_timer.system_time;
        }
        #pragma omp section
        {
            this -> user_time = given_timer.user_time;
        }
        #pragma omp section
        {
            this -> cpu_usage = given_timer.cpu_usage;
        }
        #pragma omp section
        {
            this -> name = given_timer.name;
        }
    }
};
