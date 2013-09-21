//
//
//
inline void set(const unsigned int &i, const double &value)
{
    if(is_1d_array and (not deleted_array) and (not is_const_array))
    {
        if((i > 0) and (i <= sizeof_row))
        {
            gsl_vector_set(user_1d_array, i - 1, value);
        }
    }
};
//
//
//
inline void set(const unsigned int &i, const unsigned int &j, const double &value)
{
    if(is_2d_array and (not deleted_array) and (not is_const_array))
    {
        if((i > 0) and (j > 0) and (i <= sizeof_row) and (j <= sizeof_column))
        {
            gsl_matrix_set(user_2d_array, i - 1, j - 1, value);
        }
    }
};
//
//
//
inline void set(const unsigned int &i, 
                const unsigned int &j, 
                const unsigned int &m, 
                const double &value)
{
    if(is_3d_array and (not deleted_array) and (not is_const_array))
    {
        if((i > 0)
           and (j > 0)
           and (m > 0)
           and (i <= sizeof_1st_layer)
           and (j <= sizeof_row)
           and (m <= sizeof_column))
        {
            user_3d_array[i - 1][j - 1][m - 1] = value;
        }
    }
};
//
//
//
inline void set(const unsigned int &i, 
                const unsigned int &j, 
                const unsigned int &m, 
                const unsigned int &n, 
                const double &value)
{
    if(is_4d_array and (not deleted_array) and (not is_const_array))
    {
        if((i > 0)
           and (j > 0)
           and (m > 0)
           and (n > 0)
           and (i <= sizeof_1st_layer)
           and (j <= sizeof_2nd_layer)
           and (m <= sizeof_row)
           and (n <= sizeof_column))
        {
            user_4d_array[i - 1][j - 1][m - 1][n - 1] = value;
        }
    }
};
