//
//
//
inline void copy_ranks(const array_type &input)
{
	#if CURRENT_RANK == 1
	{
		rank1 = input.rank1;
	}
	#elif CURRENT_RANK == 2
	{
		rank1 = input.rank1;
		rank2 = input.rank2;
	}
	#elif CURRENT_RANK == 3
	{
		rank1 = input.rank1;
		rank2 = input.rank2;
		rank3 = input.rank3;
	}
	#elif CURRENT_RANK == 4
	{
		rank1 = input.rank1;
		rank2 = input.rank2;
		rank3 = input.rank3;
		rank4 = input.rank4;
	}
	#else
	{
		return;
	}
	#endif
};
