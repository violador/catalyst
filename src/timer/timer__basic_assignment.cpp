//
//
//
/// @param [in] input Another previously declared @c timer object.
//
/// @brief The operator @c = will copy the content of the given @c
///        input to the current object.
//
/// @return None.
//
inline void operator =(const timer &input)
{
	#pragma omp sections nowait
	{
		#pragma omp section
		{
			this -> config = input.config;
		}
		#pragma omp section
		{
			this -> wtime = input.wtime;
		}
		#pragma omp section
		{
			this -> stime = input.stime;
		}
		#pragma omp section
		{
			this -> utime = input.utime;
		}
		#pragma omp section
		{
			this -> usage = input.usage;
		}
		#pragma omp section
		{
			this -> name = input.name;
		}
		#pragma omp section
		{
			this -> counter = input.counter;
		}
	}
};
