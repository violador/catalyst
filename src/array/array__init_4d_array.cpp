//
//
//
inline void init_4d_array(const unsigned int &local_row_size, 
                          const unsigned int &local_column_size, 
                          const unsigned int &local_1st_layer_size,
                          const unsigned int &local_2nd_layer_size)
{
    unsigned int i = 0, j = 0, m = 0, n = 0;
    user_4d_array = new double ***[local_row_size];
    #pragma omp parallel for private(i) ordered schedule(dynamic)
    for(i = 0; i < local_row_size; ++i)
    {
        user_4d_array[i] = new double **[local_column_size];
        #pragma omp parallel for private(j) ordered schedule(dynamic)
        for(j = 0; j < local_column_size; ++j)
        {
            user_4d_array[i][j] = new double *[local_1st_layer_size];
            #pragma omp parallel for private(m) ordered schedule(dynamic)
            for(m = 0; m < local_1st_layer_size; ++m)
            {
                user_4d_array[i][j][m] = new double[local_2nd_layer_size];
            }
        }
    }
    #pragma omp parallel for private(i) ordered schedule(dynamic)
    for(i = 0; i < local_row_size; ++i)
    {
        #pragma omp parallel for private(j) ordered schedule(dynamic)
        for(j = 0; j < local_column_size; ++j)
        {
            #pragma omp parallel for private(m) ordered schedule(dynamic)
            for(m = 0; m < local_1st_layer_size; ++m)
            {
                #pragma omp parallel for private(n) ordered schedule(dynamic)
                for(n = 0; n < local_2nd_layer_size; ++n)
                {
                    user_4d_array[i][j][m][n] = 0.0;
                }
            }
        }
    }
};
