//
//
//
inline void set_transpose()
{
    if(is_2d_array and (not deleted_array) and is_square_array)
    {
        gsl_matrix_transpose(&gsl_2d_view.matrix);
        is_transposed? is_transposed = false : is_transposed = true;
    }
};
