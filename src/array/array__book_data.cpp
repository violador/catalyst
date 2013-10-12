#include "array.hpp"
//
//
//
void array::book_data()
{
    global_log::file.write_debug_msg("array::book_data(): Array ID = ", array_id);
    #pragma omp parallel sections num_threads(4)
    {
        #pragma omp section
        {
            if(is_1d_array and (not deleted_array))
            {
                array_file_writer.std::ofstream::open(temp_filename.c_str(), std::ofstream::binary);
//
                for(unsigned int i = 0; i < sizeof_row; i++)
                {
                    array_file_writer.std::ofstream::write((char*) &user_1d_array -> data[i*user_1d_array -> stride], 
                                                           sizeof(double));
                }
//
                array_file_writer.std::ofstream::close();
                gsl_vector_free(user_1d_array);
            }
        }
        #pragma omp section
        {
            if(is_2d_array and (not deleted_array))
            {
                array_file_writer.std::ofstream::open(temp_filename.c_str(), std::ofstream::binary);
//
                for(unsigned int i = 0; i < sizeof_row; i++)
                {
                    for(unsigned int j = 0; j < sizeof_column; j++)
                    {
                        array_file_writer.std::ofstream::write((char*) &user_2d_array -> data[i*user_2d_array -> tda + j], 
                                                               sizeof(double));
                    }
                }
//
                array_file_writer.std::ofstream::close();
                //gsl_matrix_free(user_2d_array);
            }
        }
        #pragma omp section
        {
            if(is_3d_array and (not deleted_array))
            {
                array_file_writer.std::ofstream::open(temp_filename.c_str(), std::ofstream::binary);
//
                for(unsigned int i = 0; i < sizeof_row; i++)
                {
                    for(unsigned int j = 0; j < sizeof_column; j++)
                    {
                        for(unsigned int m = 0; m < sizeof_1st_layer; m++)
                        {
                            array_file_writer.std::ofstream::write((char*) &user_3d_array[i][j][m], 
                                                                   sizeof(double));
                        }
                    }
                }
//
                array_file_writer.std::ofstream::close();
                delete_3d_array();
            }
        }
        #pragma omp section
        {
            if(is_4d_array and (not deleted_array))
            {
                array_file_writer.std::ofstream::open(temp_filename.c_str(), std::ofstream::binary);
//
                for(unsigned int i = 0; i < sizeof_row; i++)
                {
                    for(unsigned int j = 0; j < sizeof_column; j++)
                    {
                        for(unsigned int m = 0; m < sizeof_1st_layer; m++)
                        {
                            for(unsigned int n = 0; n < sizeof_2nd_layer; n++)
                            {
                                array_file_writer.std::ofstream::write((char*) &user_4d_array[i][j][m][n], 
                                                                       sizeof(double));
                            }
                        }
                    }
                }
//
                array_file_writer.std::ofstream::close();
                delete_4d_array();
            }
        }
    } // #pragma omp parallel sections num_threads(4)
};
