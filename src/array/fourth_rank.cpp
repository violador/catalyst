//
//
//
/// @brief Returns the length of the fourth rank.
//
/// @return A nonnegative integer number.
//
inline unsigned int fourth_rank() const
{
	#if defined(RANK_FOUR_ARRAY)
		return rank4;
	#else
		return 0;
	#endif
};
