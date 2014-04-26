//
//
//
/// @brief Calculates the trace of the current array if it is a 2D,
///        square, not constant and not deleted one.
//
/// @return @f$ := tr(A) @f$.
//
inline double trace()
{
	switch(is_2d() && is_okay() && is_square())
	{
		case true:
		double trace = 0.0;
		#pragma omp for schedule(static) reduction(+: trace) nowait
		for(unsigned int i = 0; i < sizeof_row; ++i)
		{
			trace += user_2d_array[i*sizeof_row + i];
		}
		return trace;
	}
	return 0.0;
};
