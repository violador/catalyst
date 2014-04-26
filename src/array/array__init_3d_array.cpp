//
//
//
/// @param [in] row The row size.
//
/// @param [in] column The column size.
//
/// @param [in] layer The layer size.
//
/// @brief A help function to allocate memory for a 3D array.
//
/// @return None.
//
inline void init_3d_array(const unsigned int &row,
                          const unsigned int &column,
                          const unsigned int &layer)
{
	user_3d_array = new double **[row]();
	for(unsigned int i = 0; i < row; ++i)
	{
		user_3d_array[i] = new double *[column]();
		for(unsigned int j = 0; j < column; ++j)
		{
			user_3d_array[i][j] = new double [layer]();
		}
	}
};
