//
//
//
/// @brief Returns the current dimensionality.
//
/// @return A nonnegative integer number.
//
inline short unsigned int rank() const
{
	#if defined(RANK_ONE_ARRAY)
		return 1;
	#endif
	//
	#if defined(RANK_TWO_ARRAY)
		return 2;
	#endif
	//
	#if defined(RANK_THREE_ARRAY)
		return 3;
	#endif
	//
	#if defined(RANK_FOUR_ARRAY)
		return 4;
	#endif
};
