//
//
//
inline void delete_4d_array()
{
    unsigned int i = 0, j = 0, m = 0;
    #pragma omp parallel for private(i) ordered schedule(dynamic)
    for(i = 0; i < sizeof_row; ++i)             
    {
        #pragma omp parallel for private(j) ordered schedule(dynamic)
        for(j = 0; j < sizeof_column; ++j)
        {
            #pragma omp parallel for private(m) ordered schedule(dynamic)
            for(m = 0; m < sizeof_column; ++m)
            {
                delete[] user_4d_array[i][j][m];
            }
            delete[] user_4d_array[i][j];
        }
        delete[] user_4d_array[i];
    }
    delete[] user_4d_array;
};
