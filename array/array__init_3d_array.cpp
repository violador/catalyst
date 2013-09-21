//
//
//
inline void init_3d_array(const unsigned int &local_row_size, 
                          const unsigned int &local_column_size, 
                          const unsigned int &local_layer_size)
{
    unsigned int i = 0, j = 0, m = 0;
    user_3d_array = new double **[local_row_size];
    #pragma omp parallel for private(i) ordered schedule(dynamic)
    for(i = 0; i < local_row_size; ++i)
    {
        user_3d_array[i] = new double *[local_column_size];
        #pragma omp parallel for private(j) ordered schedule(dynamic)
        for(j = 0; j < local_column_size; ++j)
        {
            user_3d_array[i][j] = new double [local_layer_size];
        }
    }
    i = j = m = 0;
    #pragma omp parallel for private(i) ordered schedule(dynamic)
    for(i = 0; i < local_row_size; i++)
    {
        #pragma omp parallel for private(j) ordered schedule(dynamic)
        for(j = 0; j < local_column_size; j++)
        {
            #pragma omp parallel for private(m) ordered schedule(dynamic)
            for(m = 0; m < local_layer_size; m++)
            {
                user_3d_array[i][j][m] = 0.0;
            }
        }
    }
};
