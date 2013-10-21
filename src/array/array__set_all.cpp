//
//
//
inline void set_all(const double &value)
{
    #pragma omp parallel sections num_threads(4)
    {
        #pragma omp section
        {
            if(is_1d_array and (not deleted_array) and (not is_const_array))
            {
                gsl_vector_set_all(&gsl_1d_view.vector, value);
            }
        }
        #pragma omp section
        {
            if(is_2d_array and (not deleted_array) and (not is_const_array))
            {
                gsl_matrix_set_all(&gsl_2d_view.matrix, value);
            }
        }
        #pragma omp section
        {
            if(is_3d_array and (not deleted_array) and (not is_const_array))
            {
                unsigned int i = 0, j = 0, m = 0;
                #pragma omp parallel for private(i) ordered schedule(dynamic)
                for(i = 0; i < sizeof_1st_layer; i++)
                {
                    #pragma omp parallel for private(j) ordered schedule(dynamic)
                    for(j = 0; j < sizeof_2nd_layer; j++)
                    {
                        #pragma omp parallel for private(m) ordered schedule(dynamic)
                        for(m = 0; m < sizeof_row; m++)
                        {
                            user_3d_array[i][j][m] = value;
                        }
                    }
                }
            }
        }
        #pragma omp section
        {
            if(is_4d_array and (not deleted_array) and (not is_const_array))
            {
                unsigned int i = 0, j = 0, m = 0, n = 0;
                #pragma omp parallel for private(i) ordered schedule(dynamic)
                for(i = 0; i < sizeof_1st_layer; i++)
                {
                    #pragma omp parallel for private(j) ordered schedule(dynamic)
                    for(j = 0; j < sizeof_2nd_layer; j++)
                    {
                        #pragma omp parallel for private(m) ordered schedule(dynamic)
                        for(m = 0; m < sizeof_row; m++)
                        {
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
    } // pragma omp parallel sections num_threads(4)
}
