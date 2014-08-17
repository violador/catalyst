//
//
//
/// @brief Returns the length of the second rank.
//
/// @return A nonnegative integer number.
//
inline unsigned int second_rank() const
{
	#if defined(RANK_ONE_ARRAY)
		return 0;
	#else
		return rank2;
	#endif
};
