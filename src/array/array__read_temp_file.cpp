#include "array.hpp"
//
//
//
double array::read_temp_file(const unsigned int &i_given)
{
    double temp_value = 0.0;
    array_file_reader.std::ifstream::open(temp_filename.c_str(), std::ofstream::binary);
    for(unsigned int i = 0; i < sizeof_row; i++)
    {
//
        array_file_reader.std::ifstream::read((char*) &temp_value, sizeof(double));
//
        if(i == i_given)
        {
            array_file_reader.std::ifstream::close();
            return temp_value;
        }
    } 
    array_file_reader.std::ifstream::close();
    global_log::file.write_debug_msg("array::get(): Array ID = ",
                                     array_id,
                                     ", requested element not found in the temp file! Returning safe double-type null value...");
    return 0.0;
}
//
//
//
double array::read_temp_file(const unsigned int &i_given, 
                             const unsigned int &j_given)
{
    double temp_value = 0.0;
    array_file_reader.std::ifstream::open(temp_filename.c_str(), std::ofstream::binary);
    for(unsigned int i = 0; i < sizeof_row; i++)
    {
        for(unsigned int j = 0; j < sizeof_column; j++)
        {
//
            array_file_reader.std::ifstream::read((char*) &temp_value, sizeof(double));
//
            if((i == i_given) and (j == j_given))
            {
                array_file_reader.std::ifstream::close();
                return temp_value;
            }
        }
    }
    array_file_reader.std::ifstream::close();
    global_log::file.write_debug_msg("array::get(): Array ID = ",
                                     array_id,
                                     ", requested element not found in the temp file! Returning safe double-type null value...");
    return 0.0;
}
//
//
//
double array::read_temp_file(const unsigned int &i_given, 
                             const unsigned int &j_given,
                             const unsigned int &m_given)
{
    double temp_value = 0.0;
    array_file_reader.std::ifstream::open(temp_filename.c_str(), std::ofstream::binary);
    for(unsigned int i = 0; i < sizeof_row; i++)
    {
        for(unsigned int j = 0; j < sizeof_column; j++)
        {
            for(unsigned int m = 0; m < sizeof_1st_layer; m++)
            {
//
                array_file_reader.std::ifstream::read((char*) &temp_value, sizeof(double));
//
                if((i == i_given) and (j == j_given) and (m == m_given))
                {
                    array_file_reader.std::ifstream::close();
                    return temp_value;
                }
            }
        }
    }
    array_file_reader.std::ifstream::close();
    global_log::file.write_debug_msg("array::get(): Array ID = ",
                                     array_id,
                                     ", requested element not found in the temp file! Returning safe double-type null value...");
    return 0.0;
}
//
//
//
double array::read_temp_file(const unsigned int &i_given, 
                             const unsigned int &j_given,
                             const unsigned int &m_given,
                             const unsigned int &n_given)
{
    double temp_value = 0.0;
    array_file_reader.std::ifstream::open(temp_filename.c_str(), std::ofstream::binary);
    for(unsigned int i = 0; i < sizeof_row; i++)
    {
        for(unsigned int j = 0; j < sizeof_column; j++)
        {
            for(unsigned int m = 0; m < sizeof_1st_layer; m++)
            {
                for(unsigned int n = 0; n < sizeof_2nd_layer; n++)
                {
//
                    array_file_reader.std::ifstream::read((char*) &temp_value, sizeof(double));
//
                    if((i == i_given) 
                       and (j == j_given) 
                       and (m == m_given) 
                       and (n == n_given))
                    {
                        array_file_reader.std::ifstream::close();
                        return temp_value;
                    }
                }
            }
        }
    }
    array_file_reader.std::ifstream::close();
    global_log::file.write_debug_msg("array::get(): Array ID = ",
                                     array_id,
                                     ", requested element not found in the temp file! Returning safe double-type null value...");
    return 0.0;
}
