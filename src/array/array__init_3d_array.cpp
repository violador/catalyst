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
	data3 = new double **[row]();
	for(unsigned int i = 0; i < row; ++i)
	{
		data3[i] = new double *[column]();
		for(unsigned int j = 0; j < column; ++j)
		{
			data3[i][j] = new double [layer]();
		}
	}
};
