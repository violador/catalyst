//
//
//
inline void save_transpose_to(array &given_array)
{
    if(this -> is_2d_array 
       and given_array.is_2d_array 
       and (not given_array.is_const_array))
    {
        if((this -> sizeof_row not_eq given_array.sizeof_row) or (this -> sizeof_column not_eq given_array.sizeof_column))
        {
            given_array.resize_array(this -> sizeof_row, this -> sizeof_column);
        }
        gsl_matrix_transpose_memcpy(&given_array.gsl_2d_view.matrix, &this -> gsl_2d_view.matrix);
    }
};
