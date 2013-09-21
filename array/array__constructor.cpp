#include "array.hpp"
//
//
//
array::array()
{
    is_1d_array      = false;
    is_2d_array      = false;
    is_3d_array      = false;
    is_4d_array      = false;
    sizeof_row       = 0;
    sizeof_column    = 0;
    sizeof_1st_layer = 0;
    sizeof_2nd_layer = 0;
    sizeof_3rd_layer = 0;
    is_const_array   = false;
    is_square_array  = false;
    created_array    = false;
    deleted_array    = true;
    lowend_mode_on   = false;
    array_name       = DEFAULT_ARRAY_NAME;
}
//
//
//
array::array(const unsigned int &local_row_size)
{
    #pragma omp parallel sections num_threads(15)
    {
        #pragma omp section
        {
            tools id;
            array_id = (short unsigned int) id.generate_integral_type((long unsigned int) &array_name);
        }
        #pragma omp section
        {
            is_1d_array = true;
        }
        #pragma omp section
        {
            is_2d_array = false;
        }
        #pragma omp section
        {
            is_3d_array = false;
        }
        #pragma omp section
        {
            is_4d_array = false;
        }
        #pragma omp section
        {
            sizeof_row = local_row_size;
            user_1d_array = gsl_vector_calloc(sizeof_row);
        }
        #pragma omp section
        {
            sizeof_column = 0;
        }
        #pragma omp section
        {
            sizeof_1st_layer = 0;
        }
        #pragma omp section
        {
            sizeof_2nd_layer = 0;
        }
        #pragma omp section
        {
            sizeof_3rd_layer = 0;
        }
        #pragma omp section
        {
            is_const_array = false;
        }
        #pragma omp section
        {
            is_square_array = false;
        }
        #pragma omp section
        {
            created_array = true;
        }
        #pragma omp section
        {
            deleted_array = false;
        }
        #pragma omp section
        {
            lowend_mode_on = false;
        }
        #pragma omp section
        {
            array_name = DEFAULT_ARRAY_NAME;
        }
    }
}
//
//
//
array::array(const unsigned int &local_row_size, const unsigned int &local_column_size)
{
    #pragma omp parallel sections num_threads(14)
    {
        #pragma omp section
        {
            tools id;
            array_id = (short unsigned int) id.generate_integral_type((long unsigned int) &array_name);
        }
        #pragma omp section
        {
            is_1d_array = false;
        }
        #pragma omp section
        {
            is_2d_array = true;
        }
        #pragma omp section
        {
            is_3d_array = false;
        }
        #pragma omp section
        {
            is_4d_array = false;
        }
        #pragma omp section
        {
            sizeof_row = local_row_size;
            sizeof_column = local_column_size;
            user_2d_array = gsl_matrix_calloc(sizeof_row, sizeof_column);
        }
        #pragma omp section
        {
            sizeof_1st_layer = 0;
        }
        #pragma omp section
        {
            sizeof_2nd_layer = 0;
        }
        #pragma omp section
        {
            sizeof_3rd_layer = 0;
        }
        #pragma omp section
        {
            is_const_array = false;
        }
        #pragma omp section
        {
            is_square_array = (local_row_size == local_column_size? true : false);
        }
        #pragma omp section
        {
            created_array = true;
        }
        #pragma omp section
        {
            deleted_array = false;
        }
        #pragma omp section
        {
            lowend_mode_on = false;
        }
        #pragma omp section
        {
            array_name = DEFAULT_ARRAY_NAME;
        }
    }
}
//
//
//
array::array(const unsigned int &local_layer_size, const unsigned int &local_row_size, const unsigned int &local_column_size) 
{
    #pragma omp parallel sections num_threads(13)
    {
        #pragma omp section
        {
            tools id;
            array_id = (short unsigned int) id.generate_integral_type((long unsigned int) &array_name);
        }
        #pragma omp section
        {
            is_1d_array = false;
        }
        #pragma omp section
        {
            is_2d_array = false;
        }
        #pragma omp section
        {
            is_3d_array = true;
        }
        #pragma omp section
        {
            is_4d_array = false;
        }
        #pragma omp section
        {
            sizeof_2nd_layer = 0;
        }
        #pragma omp section
        {
            sizeof_3rd_layer = 0;
        }
        #pragma omp section
        {
            is_const_array = false;
        }
        #pragma omp section
        {
            is_square_array = false;
        }
        #pragma omp section
        {
            created_array = true;
        }
        #pragma omp section
        {
            deleted_array = false;
        }
        #pragma omp section
        {
            lowend_mode_on = false;
        }
        #pragma omp section
        {
            array_name = DEFAULT_ARRAY_NAME;
        }
    }
    sizeof_row       = local_row_size;
    sizeof_column    = local_column_size; 
    sizeof_1st_layer = local_layer_size;
    user_3d_array    = new double **[sizeof_1st_layer];
    unsigned int i = 0;
    #pragma omp parallel for private(i) ordered schedule(dynamic)
    for(i = 0; i < sizeof_1st_layer; ++i)
    {
        user_3d_array[i] = new double *[sizeof_row];
        unsigned int j = 0;
        #pragma omp parallel for private(j) ordered schedule(dynamic)
        for(j = 0; j < sizeof_row; ++j)
        {
            user_3d_array[i][j] = new double [sizeof_column];
        }
    }
/*

// Destructor (de-Allocate memory to prevent memory leak)

for (int i = 0; i < HEIGHT; ++i) 
{
    for (int j = 0; j < WIDTH; ++j)
        delete [] p2DArray[i][j];
            delete [] p2DArray[i];
}
delete [] p2DArray;

*/
}
//
//
//
array::array(const unsigned int &local_1st_layer_size, 
             const unsigned int &local_2nd_layer_size, 
             const unsigned int &local_row_size, 
             const unsigned int &local_column_size)
{ 
    #pragma omp parallel sections num_threads(12)
    {
        #pragma omp section
        {
            tools id;
            array_id = (short unsigned int) id.generate_integral_type((long unsigned int) &array_name);
        }
        #pragma omp section
        {
            is_1d_array = false;
        }
        #pragma omp section
        {
            is_2d_array = false;
        }
        #pragma omp section
        {
            is_3d_array = false;
        }
        #pragma omp section
        {
            is_4d_array = true;
        }
        #pragma omp section
        {
            is_const_array = false;
        }
        #pragma omp section
        {
            is_square_array = false;
        }
        #pragma omp section
        {
            created_array = true;
        }
        #pragma omp section
        {
            deleted_array = false;
        }
        #pragma omp section
        {
            lowend_mode_on = false;
        }
        #pragma omp section
        {
            array_name = DEFAULT_ARRAY_NAME;
        }
        #pragma omp section
        {
            sizeof_3rd_layer = 0;
        }
    }
    sizeof_row = local_row_size;
    sizeof_column = local_column_size;
    sizeof_1st_layer = local_1st_layer_size;
    sizeof_2nd_layer = local_2nd_layer_size;
    user_4d_array = new double ***[sizeof_1st_layer];
    unsigned int i = 0;
    #pragma omp parallel for private(i) ordered schedule(dynamic)
    for(i = 0; i < sizeof_1st_layer; ++i)
    {
        user_4d_array[i] = new double **[sizeof_2nd_layer];
        unsigned int j = 0;
        #pragma omp parallel for private(j) ordered schedule(dynamic)
        for(j = 0; j < sizeof_2nd_layer; ++j)
        {
            user_4d_array[i][j] = new double *[sizeof_row];
            unsigned int m = 0;
            #pragma omp parallel for private(m) ordered schedule(dynamic)
            for(m = 0; m < sizeof_row; ++m)
            {
                user_4d_array[i][j][m] = new double[sizeof_column];
            }
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
                user_3d_array = new double **[given_array.sizeof_1st_layer];
                unsigned int i = 0;
                #pragma omp parallel for private(i) ordered schedule(dynamic)
                for(i = 0; i < sizeof_1st_layer; ++i)
                {
                    user_3d_array[i] = new double *[given_array.sizeof_row];
                    unsigned int j = 0;
                    #pragma omp parallel for private(j) ordered schedule(dynamic)
                    for(j = 0; j < sizeof_row; ++j)
                    {
                        user_3d_array[i][j] = new double [given_array.sizeof_column];
                    }
                }
                i = 0;
                #pragma omp parallel for private(i) ordered schedule(dynamic)
                for(i = 0; i < given_array.sizeof_row; i++)
                {
                    unsigned int j = 0;
                    #pragma omp parallel for private(j) ordered schedule(dynamic)
                    for(j = 0; j < given_array.sizeof_column; j++)
                    {
                        unsigned int m = 0;
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
                user_4d_array = new double ***[given_array.sizeof_1st_layer];
                unsigned int i = 0;
                #pragma omp parallel for private(i) ordered schedule(dynamic)
                for(i = 0; i < sizeof_1st_layer; ++i)
                {
                    user_4d_array[i] = new double **[given_array.sizeof_2nd_layer];
                    unsigned int j = 0;
                    #pragma omp parallel for private(j) ordered schedule(dynamic)
                    for(j = 0; j < sizeof_2nd_layer; ++j)
                    {
                        user_4d_array[i][j] = new double *[given_array.sizeof_row];
                        unsigned int m = 0;
                        #pragma omp parallel for private(m) ordered schedule(dynamic)
                        for(m = 0; m < sizeof_row; ++m)
                        {
                            user_4d_array[i][j][m] = new double[given_array.sizeof_column];
                        }
                    }
                }
                i = 0;
                #pragma omp parallel for private(i) ordered schedule(dynamic)
                for(i = 0; i < given_array.sizeof_row; i++)
                {
                    unsigned int j = 0;
                    #pragma omp parallel for private(j) ordered schedule(dynamic)
                    for(j = 0; j < given_array.sizeof_column; j++)
                    {
                        unsigned int m = 0;
                        #pragma omp parallel for private(m) ordered schedule(dynamic)
                        for(m = 0; m < given_array.sizeof_1st_layer; m++)
                        {
                            unsigned int n = 0;
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
            tools id;
            array_id = (short unsigned int) id.generate_integral_type((long unsigned int) &array_name);
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
                //this -> array_file_manager.file_system::init(given_array.array_filename);
                //this -> array_file_manager.file_system::open_txt_output(this -> array_file);
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
