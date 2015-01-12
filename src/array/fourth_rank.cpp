//
//
//
/// @brief Returns the length of the fourth rank.
//
/// @return A nonnegative integer number.
//
constexpr unsigned int fourth_rank() const
{
	#if CURRENT_RANK == 4
	{
		return rank4;
	}
	#else
	{
		return 0;
	}
	#endif
};
