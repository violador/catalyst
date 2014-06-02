//
//
//
/// @brief Build its identity form, where @f$ A_{i = j} = 1 @f$ and
///        @f$ A_{i \neq j} = 0 @f$, if the current object is a rank
///        2 and square array.
//
/// @return @c EXIT_SUCCESS or @c EXIT_FAILURE.
//
int build_identity_form()
{
	switch(data != NULL && rank1 == rank2)
	{
		case false:
		{
			return EXIT_FAILURE;
		}
		case true:
		{
			#pragma omp for schedule(static) nowait
			for(unsigned int i = 0; i < rank1 - 1; ++i)
			{
				for(unsigned int j = i; j < rank2; ++j)
				{
					switch(i != j)
					{
						case false:
						{
							data2[i*rank1 + j] = 1.0;
						}
						break;
						case true:
						{
							data2[i*rank1 + j] = 0.0;
							data2[j*rank1 + i] = 0.0;
						}
						break;
					}
				}
			}
			return EXIT_SUCCESS;
		}
	}
};
