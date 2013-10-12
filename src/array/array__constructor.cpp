#include "array.hpp"
//
//
//
array::array()
{
//
    global_log::file.write_debug_msg("array::array(): No dimensions given. Invoking array::init_properties()");
//
    init_properties();
}
//
//
//
array::array(const unsigned int &local_row_size)
{
//
    global_log::file.write_debug_msg("array::array(): 1 by ",
                                     local_row_size,
                                     ". Invoking array::init_properties()");
//
    #pragma omp parallel sections num_threads(2)
    {
        #pragma omp section
        {
            init_properties(local_row_size);
        }
        #pragma omp section
        {
            user_1d_array = gsl_vector_calloc(local_row_size);
        }
    }
}
//
//
//
array::array(const unsigned int &local_row_size, const unsigned int &local_column_size)
{
//
    global_log::file.write_debug_msg("array::array(): ",
                                     local_row_size,
                                     " by ",
                                     local_column_size,
                                     ". Invoking array::init_properties()");
//
    #pragma omp parallel sections num_threads(2)
    {
        #pragma omp section
        {
            init_properties(local_row_size, local_column_size);
        }
        #pragma omp section
        {
            user_2d_array = gsl_matrix_calloc(local_row_size, local_column_size);
        }
    }
}
//
//
//
array::array(const unsigned int &local_row_size, const unsigned int &local_column_size, const unsigned int &local_layer_size) 
{
//
    global_log::file.write_debug_msg("array::array(): ",
                                     local_row_size,
                                     " by ",
                                     local_column_size,
                                     " by ",
                                     local_layer_size,
                                     ". Invoking array::init_properties()");
//
    #pragma omp parallel sections num_threads(2)
    {
        #pragma omp section
        {
            init_properties(local_row_size, local_column_size, local_layer_size);
        }
        #pragma omp section
        {
            init_3d_array(local_row_size, local_column_size, local_layer_size);
        }
    }
}
//
//
//
array::array(const unsigned int &local_row_size, 
             const unsigned int &local_column_size,
             const unsigned int &local_1st_layer_size,
             const unsigned int &local_2nd_layer_size)
{ 
//
    global_log::file.write_debug_msg("array::array(): ",
                                     local_row_size,
                                     " by ",
                                     local_column_size,
                                     " by ",
                                     local_1st_layer_size,
                                     " by ",
                                     local_2nd_layer_size,
                                     ". Invoking array::init_properties()");
//
    #pragma omp parallel sections num_threads(2)
    {
        #pragma omp section
        {
            init_properties(local_row_size, local_column_size, local_1st_layer_size, local_2nd_layer_size);
        }
        #pragma omp section
        {
            init_4d_array(local_row_size, local_column_size, local_1st_layer_size, local_2nd_layer_size);
        }
    }
}
//
//
//
array::array(const array &given_array)
{
    #pragma omp parallel sections num_threads(21)
    {
        #pragma omp section
        {
            this -> sizeof_row = given_array.sizeof_row;
            this -> sizeof_column = given_array.sizeof_column;
            this -> sizeof_1st_layer = given_array.sizeof_1st_layer;
            this -> sizeof_2nd_layer = given_array.sizeof_2nd_layer;
        }
        #pragma omp section
        {
            if(given_array.is_1d_array)
            {
                user_1d_array = gsl_vector_calloc(given_array.sizeof_row);
                gsl_vector_memcpy(this -> user_1d_array, given_array.user_1d_array); 
            }
        }
        #pragma omp section
        {
            if(given_array.is_2d_array)
            {
                user_2d_array = gsl_matrix_calloc(given_array.sizeof_row, given_array.sizeof_column);
                gsl_matrix_memcpy(this -> user_2d_array, given_array.user_2d_array);
            }
        }
        #pragma omp section
        {
            if(given_array.is_3d_array)
            {
                init_3d_array(given_array.sizeof_row, given_array.sizeof_column, given_array.sizeof_1st_layer);
                unsigned int i = 0, j = 0, m = 0;
                #pragma omp parallel for private(i) ordered schedule(dynamic)
                for(i = 0; i < given_array.sizeof_row; i++)
                {
                    #pragma omp parallel for private(j) ordered schedule(dynamic)
                    for(j = 0; j < given_array.sizeof_column; j++)
                    {
                        #pragma omp parallel for private(m) ordered schedule(dynamic)
                        for(m = 0; m < given_array.sizeof_1st_layer; m++)
                        {
                            this -> user_3d_array[i][j][m] = given_array.user_3d_array[i][j][m];
                        }
                    }
                }
            } // if(given_array.is_3d_array)
        }
        #pragma omp section
        {
            if(given_array.is_4d_array)
            {
                init_4d_array(given_array.sizeof_row, 
                              given_array.sizeof_column, 
                              given_array.sizeof_1st_layer,
                              given_array.sizeof_2nd_layer);
                unsigned int i = 0, j = 0, m = 0, n = 0;
                #pragma omp parallel for private(i) ordered schedule(dynamic)
                for(i = 0; i < given_array.sizeof_row; i++)
                {
                    #pragma omp parallel for private(j) ordered schedule(dynamic)
                    for(j = 0; j < given_array.sizeof_column; j++)
                    {
                        #pragma omp parallel for private(m) ordered schedule(dynamic)
                        for(m = 0; m < given_array.sizeof_1st_layer; m++)
                        {
                            #pragma omp parallel for private(n) ordered schedule(dynamic)
                            for(n = 0; n < given_array.sizeof_2nd_layer; n++)
                            {
                                this -> user_4d_array[i][j][m][n] = given_array.user_4d_array[i][j][m][n];
                            }
                        }
                    } 
                }
            } // if(given_array.is_4d_array)
        }
        #pragma omp section
        {
            tools id, convert;
            array_id = (short unsigned int) id.generate_integral_type((long unsigned int) &array_name);
            array_filename = "array." + convert.to_string_from(array_id);
        }
        #pragma omp section
        {
            this -> is_1d_array = given_array.is_1d_array;
        }
        #pragma omp section
        {
            this -> is_2d_array = given_array.is_2d_array;
        }
        #pragma omp section
        {
            this -> is_3d_array = given_array.is_3d_array;
        }
        #pragma omp section
        {
            this -> is_4d_array = given_array.is_4d_array;
        }
        #pragma omp section
        {
            this -> is_const_array = given_array.is_const_array;
        }
        #pragma omp section
        {
            this -> is_square_array = given_array.is_square_array;
        }
        #pragma omp section
        {
            this -> created_array = true;
        }
        #pragma omp section
        {
            this -> deleted_array = false;
        }
        #pragma omp section
        {
            this -> lowend_mode_on = given_array.lowend_mode_on;
            if(this -> lowend_mode_on)
            {
                this -> temp_filename = given_array.temp_filename;
            }
        }
        #pragma omp section
        {
            this -> array_name = DEFAULT_ARRAY_NAME;
        }
        #pragma omp section
        {
            this -> sizeof_3rd_layer = given_array.sizeof_3rd_layer;
        }
        #pragma omp section
        {
            this -> setup_ready = given_array.setup_ready;
        }
        #pragma omp section
        {
            this -> config = given_array.config;
        }
        #pragma omp section
        {
            this -> is_transposed = given_array.is_transposed;
        }
    }
}
