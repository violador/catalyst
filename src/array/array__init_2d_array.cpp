//
//
//
inline void init_2d_array(const unsigned int &local_row_size, const unsigned int &local_column_size)
{
    user_2d_array = new double[local_row_size*local_column_size];
    gsl_2d_view = gsl_matrix_view_array(user_2d_array, local_row_size, local_column_size);
    gsl_matrix_set_zero(&gsl_2d_view.matrix);
};
