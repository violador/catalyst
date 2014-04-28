//
//
//
/// @param [in] row The row size.
//
/// @param [in] column The column size.
//
/// @brief A help function to allocate memory for a 2D array.
//
/// @return None.
//
inline void init_2d_array(const unsigned int &row,
                          const unsigned int &column)
{
	data2 = new double[row*column]();
	gsl_2d_view = gsl_matrix_view_array(data2, row, column);
};
