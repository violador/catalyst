//
//
//
inline void init_2d_array(const unsigned int &row_size, 
                          const unsigned int &column_size)
{
    user_2d_array = new double[row_size*column_size];
    gsl_2d_view = gsl_matrix_view_array(user_2d_array, 
                                        row_size, 
                                        column_size);
    gsl_matrix_set_zero(&gsl_2d_view.matrix);
};
