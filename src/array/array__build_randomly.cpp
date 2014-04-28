//
//
//
/// @brief Transpose the array, @f$ A_{i, j} = A_{j, i} @f$, if it is
///        a 2D square array, not constant and not deleted.
//
/// @break @c EXIT_SUCCESS or @c EXIT_FAILURE.
//
inline void build_randomly()
{
	#pragma omp sections nowait
	{
		#pragma omp section
		{
			switch(is_1d() && is_okay())
			{
				case true:
				break;
			}
		}
		#pragma omp section
		{
			switch(is_2d() && is_okay())
			{
				case true:
				random_2d_array();
				break;
			}
		}
		#pragma omp section
		{
			switch(is_3d() && is_okay())
			{
				case true:
				break;
			}
		}
		#pragma omp section
		{
			switch(is_4d() && is_okay())
			{
				case true:
				break;
			}
		}
	}
};
