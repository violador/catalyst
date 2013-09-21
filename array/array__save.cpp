#include "array.hpp"
//
//
//
void array::save()
{
    #pragma omp parallel sections num_threads(2)
    {
        #pragma omp section
        {
            if(is_1d_array)
            {
                tools convert;
                array_filename = "array." + convert.to_string_from(array_id);
                array_file = fopen(array_filename.c_str(), "w");
                gsl_vector_fwrite(array_file, user_1d_array);
            }
        }
        #pragma omp section
        {
            if(is_2d_array)
            {
                tools convert;
                array_filename = "array." + convert.to_string_from(array_id);
                array_file = fopen(array_filename.c_str(), "w");
                gsl_matrix_fwrite(array_file, user_2d_array);
            }
        }
    }    
/*
    std::ofstream array_file(array_filename.c_str(), std::ios::binary);
    if(array_file.is_open() && array_file.good() && (!lowend_mode_on))
    {
        tools convert;
        std::string value = "";
//
        value = convert.to_string_from(sizeof_row);
        array_file.write(value.c_str(), sizeof(unsigned int));       
//
        value = convert.to_string_from(sizeof_column);
        array_file.write(value.c_str(), sizeof(unsigned int));       
//
        for(unsigned int i = 0; i < sizeof_row; i++)
        {
            for(unsigned int j = 0; j < sizeof_column; j++)
            {
                value = convert.to_string_from(gsl_matrix_get(user_2d_array, i, j));
                array_file.write(value.c_str(), sizeof(double));
            }
        }
        array_file.close();
    }
    else if(array_file.is_open() && array_file.good() && lowend_mode_on)
    {
        #define SPACE_LENGTH 5
//
        array_file.width(7);
        array_file << std::left << sizeof_row;
//
        array_file.width(7);
        array_file << std::left << sizeof_column;
//
        for(unsigned int i = 0; i < sizeof_row; i++)
        {
            for(unsigned int j = 0; j < sizeof_column; j++)
            {
                array_file.precision(MAX_PRECISION);
                array_file.width(MAX_PRECISION + SPACE_LENGTH);
                array_file << std::left << gsl_matrix_get(user_2d_array, i, j);
            }
        }
        array_file.close();
    }
    else
    {
        std::cout << "ERROR: Was not possible to open the file!" << std::endl;
    }
*/
}
//
//
//
/*
void array::save_to()
{
    #define SPACE_LENGTH 5
//
    array_file.width(7);
    array_file << std::left << sizeof_row;
//
    array_file.width(7);
    array_file << std::left << sizeof_column;
//
    for(unsigned int i = 0; i < sizeof_row; i++)
    {
        for(unsigned int j = 0; j < sizeof_column; j++)
        {
            array_file.precision(MAX_PRECISION);
            array_file.width(MAX_PRECISION + SPACE_LENGTH);
            array_file << std::left << gsl_matrix_get(user_2d_array, i, j);
        }
    }
}
*/
