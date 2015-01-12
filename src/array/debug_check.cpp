//
//
//
void debug_check()
{
//
	#if defined(PARALLEL_MODE)
	{
		#undef PARALLEL_MODE
	}
	#endif
//
	#if defined(RANK_TWO_SHAPE)
	{
		#undef RANK_TWO_SHAPE
	}
	#endif
//
	#if defined(USE_PARALLEL_ARRAY_CLASS)
	{
		#define PARALLEL_MODE "yes"
	}
	#else
	{
		#define PARALLEL_MODE "no"
	}
	#endif
//
	#if CURRENT_RANK == 2
	{
		#define RANK_TWO_SHAPE (is_square()? "yes" : "no")
	}
	#else
	{
		#define RANK_TWO_SHAPE "no"
	}
	#endif
//
	std::cout << "Current rank order = " << rank() << std::endl
	          << "Length of first rank  = " << first_rank()  << std::endl
	          << "Length of second rank = " << second_rank() << std::endl
	          << "Length of third rank  = " << third_rank()  << std::endl
	          << "Length of fourth rank = " << fourth_rank() << std::endl
	          << "Memory allocation = " << (is_ready()? "done" : "not done") << std::endl
	          << "Data begin = " << data << std::endl
	          << "Data end = " << data_end() << std::endl
	          << "Internal data length = " << data_length() << std::endl
	          << "Data type = " << data_typename() << std::endl
	          << "Is null = " << (is_null()? "yes" : "no") << std::endl
	          << "Is positive = " << (is_positive()? "yes" : "no") << std::endl
	          << "Is negative = " << (is_negative()? "yes" : "no") << std::endl
	          << "Is square = " << RANK_TWO_SHAPE << std::endl
	          << "Minimum value found = " << min() << std::endl
	          << "Maximum value found = " << max() << std::endl
	          << "NaN values found = " << (has_nan()? "yes" : "no") << std::endl
	          << "Thread paralelization = " << PARALLEL_MODE  << std::endl
	          << "OMP_STATIC_LOOP_POLICY = #pragma " << OMP_STATIC_LOOP << std::endl
	          << "OMP_DYNAMIC_LOOP_POLICY = #pragma " << OMP_DYNAMIC_LOOP << std::endl;
//
	#undef PARALLEL_MODE
	#undef RANK_TWO_SHAPE
};
