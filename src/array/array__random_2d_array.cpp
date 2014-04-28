#include "array.hpp"
//
//
//
/// @brief
//
/// @return None.
//
void array::random_2d_array()
{
	switch(is_square() && rank1 > 30)
	{
		case false:
		{
			#pragma omp for schedule(static) nowait
			for(unsigned int i = 0; i < rank1; ++i)
			{
				for(unsigned int j = 0; j < rank2; ++j)
				{
					data2[i*rank1 + j] = tools::random_number<double>((unsigned long int) i + j);
				}
			}
		}
		break;
		case true:
		{
			#pragma omp for schedule(static) nowait
			for(unsigned int i = 0; i < rank1 - 1; ++i)
			{
				for(unsigned int j = i; j < rank2; ++j)
				{
					switch(i == j)
					{
						case false:
						{
							data2[i*rank1 + j] = tools::random_number<double>((unsigned long int) i + j);
							data2[j*rank1 + i] = tools::random_number<double>((unsigned long int) i - j);
						}
						break;
						case true:
						{
							data2[i*rank1 + j] = tools::random_number<double>((unsigned long int) i*j);
						}
						break;
					}
				}
			}
		}
		break;
	}
}
