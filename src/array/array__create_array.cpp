//
//
//
inline void create_array(const unsigned int &row_size)
{
    switch(deleted_array)
    {
        case true: 
        {
            deleted_array = false;
            sizeof_row = row_size;
            init_1d_array(row_size);
        } 
        break;
    }
};
//
//
//
inline void create_array(const unsigned int &row_size,
                         const unsigned int &column_size)
{
    switch(deleted_array)
    {
        case true: 
        {
            deleted_array = false;
            sizeof_row = row_size;
            sizeof_column = column_size;
            init_2d_array(row_size, column_size);
            row_size == column_size? is_square_array = true : is_square_array = false;
        }
        break;
    }
};
//
//
//
inline void create_array(const unsigned int &row_size,
                         const unsigned int &column_size,
                         const unsigned int &layer1_size)
{
    switch(deleted_array)
    {
        case true: 
        {
            deleted_array = false;
            sizeof_row = row_size;
            sizeof_column = column_size;
            sizeof_1st_layer = layer1_size;
            init_3d_array(row_size, column_size, layer1_size);
        }
        break;
    }
};
//
//
//
inline void create_array(const unsigned int &row_size,
                         const unsigned int &column_size,
                         const unsigned int &layer1_size,
                         const unsigned int &layer2_size)
{
    switch(deleted_array)
    {
        case true: 
        {
            deleted_array = false;
            sizeof_row = row_size;
            sizeof_column = column_size;
            sizeof_1st_layer = layer1_size;
            sizeof_2nd_layer = layer2_size;
            init_4d_array(row_size, column_size, layer1_size, layer2_size);
        } 
        break;
    }
};
