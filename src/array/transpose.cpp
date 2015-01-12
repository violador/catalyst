//
//
//
/// @brief Transpose a rank two array if it is square and was previously
/// initialized either by construction or the array::create() member
/// function. Otherwise nohing is done.
//
/// @return None.
//
void transpose()
{
	if(is_square())
	{
//
//		Note: The loop runs over the upper triangle part only and avoids to
//		touch the diagonal. The last element must be i = first_rank() - 1
//		and j = first_rank() = second_rank().
//
		OMP_STATIC_LOOP_POLICY
		for(INIT_ITER(i, 1); i < first_rank(); ++i)
		{
			for(unsigned int j(i + 1); j <= second_rank(); ++j)
			{
				std::swap(data[offset(i, j)], data[offset(j, i)]);
			}
		}
	}
};
