//
//
//
inline void init_3d_array(const unsigned int &row_size, 
                          const unsigned int &column_size, 
                          const unsigned int &layer_size)
{
    unsigned int i = 0, j = 0, m = 0;
    user_3d_array = new double **[row_size];
    #pragma omp parallel for private(i) ordered schedule(dynamic)
    for(i = 0; i < row_size; ++i)
    {
        user_3d_array[i] = new double *[column_size];
        #pragma omp parallel for private(j) ordered schedule(dynamic)
        for(j = 0; j < column_size; ++j)
        {
            user_3d_array[i][j] = new double [layer_size];
        }
    }
    #pragma omp parallel for private(i) ordered schedule(dynamic)
    for(i = 0; i < row_size; ++i)
    {
        #pragma omp parallel for private(j) ordered schedule(dynamic)
        for(j = 0; j < column_size; ++j)
        {
            #pragma omp parallel for private(m) ordered schedule(dynamic)
            for(m = 0; m < layer_size; ++m)
            {
                user_3d_array[i][j][m] = 0.0;
            }
        }
    }
};
