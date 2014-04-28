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
		#define CHUNK tools::omp_chunk(rank1 - 1)
		#pragma omp for schedule(dynamic, CHUNK) nowait
		for(unsigned int i = 0; i < rank1 - 1; ++i)
		{
			for(unsigned int j = i + 1; j < rank2; ++j)
			{
				double ij = data2[i*rank1 + j];
				double ji = data2[j*rank1 + i];
				data2[i*rank1 + j] = ji;
				data2[j*rank1 + i] = ij;
			}
		}
		#undef CHUNK
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
};
