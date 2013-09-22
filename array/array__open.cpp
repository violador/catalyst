#include "array.hpp"
//
//
//
void array::open()
{
    #pragma omp parallel sections num_threads(2)
    {
        #pragma omp section
        {
            if(is_1d_array)
            {
                array_file = fopen(array_filename.c_str(), "r");
                gsl_vector_fread(array_file, user_1d_array);
            }
        }
        #pragma omp section
        {
            if(is_2d_array)
            {
                array_file = fopen(array_filename.c_str(), "r");
                gsl_matrix_fread(array_file, user_2d_array);
            }
        }
    }
}
/*
void array::open(const std::string &array_filename)
{
    std::ifstream array_file(array_filename.c_str(), std::ios::in | std::ios::binary);
    if(array_file.is_open() && array_file.good())
    {
        array_file >> sizeof_row;
        array_file >> sizeof_column;
        double value = 0.0;
        for(unsigned int i = 0; i < sizeof_row; i++)
        {
            for(unsigned int j = 0; j < sizeof_column; j++)
            {
                array_file >> value;
                gsl_matrix_set(user_2d_array, i, j, value);
                value = 0.0;
            }
        }
        array_file.close();
    }
    else
    {
        std::cout << "ERROR: Was not possible to open the file!" << std::endl;
    }
}
*/
