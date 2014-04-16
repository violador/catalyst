//
//
//
inline void init_1d_array(const unsigned int &row_size)
{
	user_1d_array = new double[row_size];
	gsl_1d_view = gsl_vector_view_array(user_1d_array, row_size);
	gsl_vector_set_zero(&gsl_1d_view.vector);
};
