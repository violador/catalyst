//
//
//
inline void delete_3d_array()
{
    unsigned int i = 0, j = 0;
    #pragma omp parallel for private(i) ordered schedule(dynamic)
    for(i = 0; i < sizeof_row; i++) 
    {
        #pragma omp parallel for private(j) ordered schedule(dynamic)
        for(j = 0; j < sizeof_column; j++)
        {
            delete[] user_3d_array[i][j];
        }
        delete[] user_3d_array[i];
    }
    delete[] user_3d_array;
};
