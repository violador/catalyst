//
//
//
/// @brief Returns the length of the third rank.
//
/// @return A nonnegative integer number.
//
constexpr unsigned int third_rank() const
{
	#if CURRENT_RANK < 3
	{
		return 0;
	}
	#else
	{
		return rank3;
	}
	#endif
};
