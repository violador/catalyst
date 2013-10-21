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
                return user_1d_array[i - 1];
            }
            else
            {
                global_log::file.write_debug_msg("array::get(): Array ID = ", 
                                                 array_id, 
                                                 ", requested element out of range! Returning safe double-type null value...");
                return 0.0;
            }
        }
        else
        {
            if((i > 0) and (i <= sizeof_row))
            {
                return read_temp_file(i - 1);
            }
            else
            {
                global_log::file.write_debug_msg("array::get(): Array ID = ", 
                                                 array_id, 
                                                 ", requested element out of range! Returning safe double-type null value...");
                return 0.0;
            }
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
            if((i > 0) and (j > 0) and (i <= sizeof_row) and (j <= sizeof_column))
            { 
                return user_2d_array[(i - 1)*sizeof_row + (j - 1)]; 
            }
            else
            {
                global_log::file.write_debug_msg("array::get(): Array ID = ", 
                                                 array_id, 
                                                 ", requested element out of range! Returning safe double-type null value...");
                return 0.0;
            }
        }
        else
        {
            if((i > 0) and (j > 0) and (i <= sizeof_row) and (j <= sizeof_column))
            { 
                return read_temp_file(i - 1, j - 1);
            }
            else
            {
                global_log::file.write_debug_msg("array::get(): Array ID = ", 
                                                 array_id, 
                                                 ", requested element out of range! Returning safe double-type null value...");
                return 0.0;
            }
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
               and (i <= sizeof_row)
               and (j <= sizeof_column)
               and (m <= sizeof_1st_layer))
            {
                return user_3d_array[i - 1][j - 1][m - 1];
            }
            else
            { 
                global_log::file.write_debug_msg("array::get(): Array ID = ", 
                                                 array_id, 
                                                 ", requested element out of range! Returning safe double-type null value...");
                return 0.0;
            }
        }
        else
        {  
            if((i > 0) 
               and (j > 0) 
               and (i <= sizeof_row) 
               and (j <= sizeof_column)
               and (m <= sizeof_1st_layer))
            { 
                return read_temp_file(i - 1, j - 1, m - 1);
            }
            else
            {
                global_log::file.write_debug_msg("array::get(): Array ID = ", 
                                                 array_id, 
                                                 ", requested element out of range! Returning safe double-type null value...");
                return 0.0;
            }
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
               and (i <= sizeof_row)
               and (j <= sizeof_column)
               and (m <= sizeof_1st_layer)
               and (n <= sizeof_2nd_layer))
            {
                return user_4d_array[i - 1][j - 1][m - 1][n - 1];
            }
            else
            {
                global_log::file.write_debug_msg("array::get(): Array ID = ", 
                                                 array_id, 
                                                 ", requested element out of range! Returning safe double-type null value...");
                return 0.0;
            }
        }
        else
        {
            if((i > 0) 
               and (j > 0)
               and (m > 0)
               and (n > 0)
               and (i <= sizeof_row)
               and (j <= sizeof_column)
               and (m <= sizeof_1st_layer)
               and (n <= sizeof_2nd_layer))
            {
                return read_temp_file(i - 1, j - 1, m - 1, n - 1);
            }
            else
            {
                global_log::file.write_debug_msg("array::get(): Array ID = ", 
                                                 array_id, 
                                                 ", requested element out of range! Returning safe double-type null value...");
                return 0.0;
            }
        }
    }
    else
    {
        return 0.0;
    }
};
