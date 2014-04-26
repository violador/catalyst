//
//
//
/// @brief Build its identity form, where @f$ A_{i = j} = 1 @f$ and
///        @f$ A_{i \neq j} = 0 @f$, if the current array is a 2D,
///        square, not constant and not deleted object.
//
/// @return @c EXIT_SUCCESS or @c EXIT_FAILURE.
//
inline int build_identity_form()
{
//
/// @warning @modification_warn
//
	switch(is_2d() && is_okay() && is_square())
	{
		case true:
		#pragma omp for schedule(dynamic) nowait
		for(unsigned int i = 0; i < sizeof_row - 1; ++i)
		{
			for(unsigned int j = i; j < sizeof_column; ++j)
			{
				switch(i == j)
				{
					case false:
					{
						user_2d_array[i*sizeof_row + j] = 0.0;
						user_2d_array[j*sizeof_row + i] = 0.0;
					}
					break;
					case true:
					{
						user_2d_array[i*sizeof_row + j] = 1.0;
					}
					break;
				}
			}
		}
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
};
