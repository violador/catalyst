//
//
//
inline double get(const unsigned int &i)
{
    if(is_1d_array and (not deleted_array))
    {
        if(not lowend_mode_on)
        {
            if((i > 0) and (i <= sizeof_row))
            {
                return user_1d_array -> data[(i - 1)*user_1d_array -> stride];
            }
            else
            {
                return 0.0;
            }
        }
        else
        {
            // lowend_mode AQUI!
            return 0.0;
        }
    }
    else
    {
        return 0.0;
    }
}
//
//
//
inline double get(const unsigned int &i, const unsigned int &j)
{
    if(is_2d_array and (not deleted_array))
    {
        if(not lowend_mode_on)
        {
            if(not is_transposed)
            {
                if((i > 0) and (j > 0) and (i <= sizeof_row) and (j <= sizeof_column))
                { 
                    return user_2d_array -> data[(i - 1)*user_2d_array -> tda + (j - 1)]; 
                }
                else
                {
                    return 0.0;
                }
            }
            else
            {
                if((i > 0) and (j > 0) and (i <= sizeof_row) and (j <= sizeof_column))
                {
                    return user_2d_array -> data[(j - 1)*user_2d_array -> tda + (i - 1)];
                }
                else
                {
                    return 0.0;
                }
            }
        }
        else
        {
            std::cout << "READING FROM TEMP FILE" << std::endl;
            return read_temp_file(i, j);
        }
    }
    else
    {
        return 0.0;
    }
}
//
//
//
inline double get(const unsigned int &i, const unsigned int &j, const unsigned int &m)
{
    if(is_3d_array and (not deleted_array))
    {
        if(not lowend_mode_on)
        {
            if((i > 0)
               and (j > 0)
               and (m > 0)
               and (i <= sizeof_1st_layer)
               and (j <= sizeof_row)
               and (m <= sizeof_column))
            {
                return user_3d_array[i - 1][j - 1][m - 1];
            }
            else
            {
                return 0.0;
            }
        }
        else
        {  
            // lowend_mode AQUI!
            return 0.0;
        }
    }
    else
    {
        return 0.0;
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
    if(is_4d_array and (not deleted_array))
    {
        if(not lowend_mode_on)
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
                return user_4d_array[i - 1][j - 1][m - 1][n - 1];
            }
            else
            {
                return 0.0;
            }
        }
        else
        {
            // lowend_mode AQUI!
            return 0.0;
        }
    }
    else
    {
        return 0.0;
    }
};
