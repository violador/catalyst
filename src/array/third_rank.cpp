//
//
//
/// @brief Returns the length of the third rank.
//
/// @return A nonnegative integer number.
//
inline unsigned int third_rank() const
{
	#if defined(RANK_ONE_ARRAY) || defined(RANK_TWO_ARRAY)
		return 0;
	#else
		return rank3;
	#endif
};
