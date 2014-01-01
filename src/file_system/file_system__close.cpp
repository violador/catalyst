//
//
//
inline void close(std::fstream &file)
{
    file.std::fstream::close();
};
//
//
//
inline void close()
{
    #pragma omp parallel sections num_threads(2)
    {
        #pragma omp section
        {
            switch(input_file.std::fstream::is_open())
            {
                case true: 
                input_file.std::fstream::close(); 
                break;
            }
        }
        #pragma omp section
        {
            switch(output_file.std::fstream::is_open())
            {
                case true: 
                output_file.std::fstream::close(); 
                break;
            }
        }
    }
};
