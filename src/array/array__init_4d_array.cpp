//
//
//
inline void init_4d_array(const unsigned int &row_size, 
                          const unsigned int &column_size, 
                          const unsigned int &layer1_size,
                          const unsigned int &layer2_size)
{
    unsigned int i = 0, j = 0, m = 0, n = 0;
    user_4d_array = new double ***[row_size];
    #pragma omp parallel for private(i) ordered schedule(dynamic)
    for(i = 0; i < row_size; ++i)
    {
        user_4d_array[i] = new double **[column_size];
        #pragma omp parallel for private(j) ordered schedule(dynamic)
        for(j = 0; j < column_size; ++j)
        {
            user_4d_array[i][j] = new double *[layer1_size];
            #pragma omp parallel for private(m) ordered schedule(dynamic)
            for(m = 0; m < layer1_size; ++m)
            {
                user_4d_array[i][j][m] = new double[layer2_size];
            }
        }
    }
    #pragma omp parallel for private(i) ordered schedule(dynamic)
    for(i = 0; i < row_size; ++i)
    {
        #pragma omp parallel for private(j) ordered schedule(dynamic)
        for(j = 0; j < column_size; ++j)
        {
            #pragma omp parallel for private(m) ordered schedule(dynamic)
            for(m = 0; m < layer1_size; ++m)
            {
                #pragma omp parallel for private(n) ordered schedule(dynamic)
                for(n = 0; n < layer2_size; ++n)
                {
                    user_4d_array[i][j][m][n] = 0.0;
                }
            }
        }
    }
};
