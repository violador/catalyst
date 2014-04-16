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
	#pragma omp sections
	{
		#pragma omp section
		{
			this -> config = input.config;
		}
		#pragma omp section
		{
			this -> wall_time = input.wall_time;
		}
		#pragma omp section
		{
			this -> system_time = input.system_time;
		}
		#pragma omp section
		{
			this -> user_time = input.user_time;
		}
		#pragma omp section
		{
			this -> cpu_usage = input.cpu_usage;
		}
		#pragma omp section
		{
			this -> name = input.name;
		}
	}
};
