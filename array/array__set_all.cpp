//
//
//
inline void set_all(const double &value)
{
    if(is_1d_array and (not deleted_array) and (not is_const_array))
    {
        gsl_vector_set_all(user_1d_array, value);
    }
    else if(is_2d_array and (not deleted_array) and (not is_const_array))
    {
        gsl_matrix_set_all(user_2d_array, value);
    }
    else if(is_3d_array and (not deleted_array) and (not is_const_array))
    {
        unsigned int i = 0;
        #pragma omp parallel for private(i) ordered schedule(dynamic)
        for(i = 0; i < sizeof_1st_layer; i++)
        {
            unsigned int j = 0;
            #pragma omp parallel for private(j) ordered schedule(dynamic)
            for(j = 0; j < sizeof_2nd_layer; j++)
            {
                unsigned int m = 0;
                #pragma omp parallel for private(m) ordered schedule(dynamic)
                for(m = 0; m < sizeof_row; m++)
                {
                    user_3d_array[i][j][m] = value;
                }
            }
        }
    }
    else if(is_4d_array and (not deleted_array) and (not is_const_array))
    {
        unsigned int i = 0;
        #pragma omp parallel for private(i) ordered schedule(dynamic)
        for(i = 0; i < sizeof_1st_layer; i++)
        {
            unsigned int j = 0;
            #pragma omp parallel for private(j) ordered schedule(dynamic)
            for(j = 0; j < sizeof_2nd_layer; j++)
            {
                unsigned int m = 0;
                #pragma omp parallel for private(m) ordered schedule(dynamic)
                for(m = 0; m < sizeof_row; m++)
                {
                    unsigned int n = 0;
                    #pragma omp parallel for private(n) ordered schedule(dynamic)
                    for(n = 0; n < sizeof_column; n++)
                    {
                        user_4d_array[i][j][m][n] = value;
                    }
                }
            }
        }
    }
}
