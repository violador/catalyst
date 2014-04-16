//
//
//
inline void init(const std::string &given_pathname,
                 const std::string &given_filename) 
{
    #pragma omp parallel sections num_threads(2)
    {
        #pragma omp section
        {
            input = init_file(given_filename, given_pathname);
        }
        #pragma omp section
        {
            disk_info = init_path(given_pathname);
        }
    }
    update();
};
