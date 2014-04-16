//
//
//
/// @param [in] value A real number.
//
/// @brief A help function used to set up the given value into all the
///        elements if the current object is not a deleted or constant
///        3D array.
//
/// @return None.
//
inline void set_all_3d_elements(const double &value)
{
	switch(is_3d_array
	       and (not deleted_array)
	       and (not is_const_array))
	{
		case true:
		#pragma omp for schedule(static) nowait
		for(unsigned int i = 0; i < sizeof_row; ++i)
		{
			for(unsigned int j = 0; j < sizeof_column; ++j)
			{
				for(unsigned int m = 0; m < sizeof_1st_layer; ++m)
				{
					user_3d_array[i][j][m] = value;
				}
			}
		}
		break;
	}
};
