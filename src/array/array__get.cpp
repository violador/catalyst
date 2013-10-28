//
//
//
inline double get(const unsigned int &i)
{
    switch(is_1d_array 
           and (not deleted_array)
           and (i >= 1)
           and (i <= sizeof_row))
    {
        case false: return 0.0; break;
        case  true: return user_1d_array[i - 1]; break;
    }
};
//
//
//
inline double get(const unsigned int &i, const unsigned int &j)
{
    switch(is_2d_array 
           and (not deleted_array)
           and (i >= 1) 
           and (j >= 1) 
           and (i <= sizeof_row) 
           and (j <= sizeof_column))
    {
        case false: return 0.0; break;
        case  true: return user_2d_array[(i - 1)*sizeof_row + (j - 1)]; break;
    }
};
//
//
//
inline double get(const unsigned int &i, const unsigned int &j, const unsigned int &m)
{
    switch(is_3d_array 
           and (not deleted_array)
           and (i >= 1)
           and (j >= 1)
           and (m >= 1)
           and (i <= sizeof_row)
           and (j <= sizeof_column)
           and (m <= sizeof_1st_layer))
    {
        case false: return 0.0; break;
        case  true: return user_3d_array[i - 1][j - 1][m - 1]; break;
    }
};
//
//
//
inline double get(const unsigned int &i, 
                  const unsigned int &j, 
                  const unsigned int &m, 
                  const unsigned int &n)
{ 
    switch(is_4d_array 
           and (not deleted_array)
           and (i >= 1)
           and (j >= 1)
           and (m >= 1)
           and (n >= 1)
           and (i <= sizeof_row)
           and (j <= sizeof_column)
           and (m <= sizeof_1st_layer)
           and (n <= sizeof_2nd_layer))
    {
        case false: return 0.0; break;
        case  true: return user_4d_array[i - 1][j - 1][m - 1][n - 1]; break;
    }
};
