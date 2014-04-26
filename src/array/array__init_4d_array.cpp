//
//
//
/// @param [in] row The row size.
//
/// @param [in] column The column size.
//
/// @param [in] layer1 The first layer size.
//
/// @param [in] layer2 The second layer size.
//
/// @brief A help function to allocate memory for a 4D array.
//
/// @return None.
//
inline void init_4d_array(const unsigned int &row,
                          const unsigned int &column,
                          const unsigned int &layer1,
                          const unsigned int &layer2)
{
	user_4d_array = new double ***[row]();
	for(unsigned int i = 0; i < row; ++i)
	{
		user_4d_array[i] = new double **[column]();
		for(unsigned int j = 0; j < column; ++j)
		{
			user_4d_array[i][j] = new double *[layer1]();
			for(unsigned int m = 0; m < layer1; ++m)
			{
				user_4d_array[i][j][m] = new double[layer2]();
			}
		}
	}
};
