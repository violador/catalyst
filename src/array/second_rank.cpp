//
//
//
/// @brief Returns the length of the second rank.
//
/// @return A nonnegative integer number.
//
constexpr unsigned int second_rank() const
{
	#if CURRENT_RANK == 1
	{
		return 0;
	}
	#else
	{
		return rank2;
	}
	#endif
};
