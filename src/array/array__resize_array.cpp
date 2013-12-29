//
//
//
inline void resize_array(const unsigned int &local_row_size)
{
    delete_1d_array();
    init_1d_array(local_row_size);
    sizeof_row = local_row_size;
};
//
//
//
inline void resize_array(const unsigned int &local_row_size,
                         const unsigned int &local_column_size)
{
    #pragma omp parallel sections num_threads(2)
    {
        #pragma omp section
        {
            delete_2d_array();
            init_2d_array(local_row_size, 
                          local_column_size);
        }
        #pragma omp section
        {
            sizeof_row = local_row_size;
            sizeof_column = local_column_size;
            sizeof_row == sizeof_column? is_square_array = true : is_square_array = false;
        }
    }
};
//
//
//
inline void resize_array(const unsigned int &local_row_size,
                         const unsigned int &local_column_size,
                         const unsigned int &local_1st_layer_size)
{
    #pragma omp parallel sections num_threads(2)
    {
        #pragma omp section
        {
            delete_3d_array();
            init_3d_array(local_row_size, 
                          local_column_size, 
                          local_1st_layer_size);
        }
        #pragma omp section
        {
            sizeof_row = local_row_size;
            sizeof_column = local_column_size;
            sizeof_1st_layer = local_1st_layer_size;
            sizeof_row == sizeof_column? is_square_array = true : is_square_array = false;
        }
    }
};
//
//
//
inline void resize_array(const unsigned int &local_row_size,
                         const unsigned int &local_column_size,
                         const unsigned int &local_1st_layer_size,
                         const unsigned int &local_2nd_layer_size)
{
    #pragma omp parallel sections num_threads(2)
    {
        #pragma omp section
        {
            delete_4d_array();
            init_4d_array(local_row_size, 
                          local_column_size, 
                          local_1st_layer_size, 
                          local_2nd_layer_size);
        }
        #pragma omp section
        {
            sizeof_row = local_row_size;
            sizeof_column = local_column_size;
            sizeof_1st_layer = local_1st_layer_size;
            sizeof_2nd_layer = local_2nd_layer_size;
            sizeof_row == sizeof_column? is_square_array = true : is_square_array = false;
        }
    }
};
