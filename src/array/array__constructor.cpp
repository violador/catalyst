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
    global_log::file.write_debug_msg("array::array(): Dimensions requested = 1 by ",
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
            init_1d_array(local_row_size);
        }
    }
}
//
//
//
array::array(const unsigned int &local_row_size, const unsigned int &local_column_size)
{
//
    global_log::file.write_debug_msg("array::array(): Dimensions requested = ",
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
            init_2d_array(local_row_size, local_column_size);
        }
    }
}
//
//
//
array::array(const unsigned int &local_row_size, const unsigned int &local_column_size, const unsigned int &local_layer_size) 
{
//
    global_log::file.write_debug_msg("array::array(): Dimensions requested = ",
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
    global_log::file.write_debug_msg("array::array(): Dimensions requested = ",
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
    #pragma omp parallel sections num_threads(4)
    {
        #pragma omp section
        {
            switch(given_array.is_1d_array)
            {
                case true:
                #pragma omp parallel sections num_threads(2)
                {
                    #pragma omp section
                    {
                        init_properties(given_array.sizeof_row);
                    }
                    #pragma omp section
                    {
                        init_1d_array(given_array.sizeof_row);
                    }
                }
                gsl_vector_memcpy(&this -> gsl_1d_view.vector, &given_array.gsl_1d_view.vector);
                break;
            }
        }
        #pragma omp section
        {
            switch(given_array.is_2d_array)
            {
                case true:
                #pragma omp parallel sections num_threads(2)
                {
                    #pragma omp section
                    {
                        init_properties(given_array.sizeof_row, given_array.sizeof_column);
                    }
                    #pragma omp section
                    {
                        init_2d_array(given_array.sizeof_row, given_array.sizeof_column);
                    }
                }
                gsl_matrix_memcpy(&this -> gsl_2d_view.matrix, &given_array.gsl_2d_view.matrix);
                break;
            }
        }
        #pragma omp section
        {
            switch(given_array.is_3d_array)
            {
                case true:
                #pragma omp parallel sections num_threads(2)
                {
                    #pragma omp section
                    {
                        init_properties(given_array.sizeof_row, 
                                        given_array.sizeof_column,
                                        given_array.sizeof_1st_layer);
                    }
                    #pragma omp section
                    {
                        init_3d_array(given_array.sizeof_row, 
                                      given_array.sizeof_column,
                                      given_array.sizeof_1st_layer);
                    }
                }
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
                break;
            }
        }
        #pragma omp section
        {
            switch(given_array.is_4d_array)
            {
                case true:
                #pragma omp parallel sections num_threads(2)
                {
                    #pragma omp section
                    {
                        init_properties(given_array.sizeof_row, 
                                        given_array.sizeof_column,
                                        given_array.sizeof_1st_layer,
                                        given_array.sizeof_2nd_layer);
                    }
                    #pragma omp section
                    {
                        init_4d_array(given_array.sizeof_row, 
                                      given_array.sizeof_column,
                                      given_array.sizeof_1st_layer,
                                      given_array.sizeof_2nd_layer);
                    }
                }
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
                break;
            }
        }
    } // #pragma omp parallel sections num_threads(4)
}
