//
//
//
/// @param [in] value A real number.
//
/// @brief A help function used to set up the given value into all the
///        elements if the current object is not a deleted or constant
///        4D array.
//
/// @return None.
//
inline void set_all_4d_elements(const double &value)
{
	switch(is_4d() && is_okay())
	{
		case true:
		#pragma omp for schedule(static) nowait
		for(unsigned int i = 0; i < rank1; ++i)
		{
			for(unsigned int j = 0; j < rank2; ++j)
			{
				for(unsigned int m = 0; m < rank3; ++m)
				{
					for(unsigned int n = 0; n < rank4; ++n)
					{
						data4[i][j][m][n] = value;
					}
				}
			}
		}
		return;
	}
};
