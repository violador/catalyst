//
//
//
/// @brief Transpose the array, @f$ A_{i, j} = A_{j, i} @f$, if it is
///        a 2D square array, not constant and not deleted.
//
/// @return @c EXIT_SUCCESS or @c EXIT_FAILURE.
//
inline int transpose()
{
	switch(is_2d() && is_okay() && is_square())
	{
		case true:
		#define CHUNK tools::omp_chunk(sizeof_row - 1)
		#pragma omp for schedule(dynamic, CHUNK) nowait
		for(unsigned int i = 0; i < sizeof_row - 1; ++i)
		{
			for(unsigned int j = i + 1; j < sizeof_column; ++j)
			{
				double ij = user_2d_array[i*sizeof_row + j];
				double ji = user_2d_array[j*sizeof_row + i];
				user_2d_array[i*sizeof_row + j] = ji;
				user_2d_array[j*sizeof_row + i] = ij;
			}
		}
		#undef CHUNK
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
};
