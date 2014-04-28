//
//
//
/// @param [in] row The row size.
//
/// @brief A help function to allocate memory for an 1D array.
//
/// @return None.
//
inline void init_1d_array(const unsigned int &row)
{
	data1 = new double[row]();
	gsl_1d_view = gsl_vector_view_array(data1, row);
};
