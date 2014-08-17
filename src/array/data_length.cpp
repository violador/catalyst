//
//
//
/// @brief A help function used to check the internal real length
///        of the current array.
//
/// @return A nonnegative integer.
//
inline unsigned int data_length() const
{
	#if defined(RANK_ONE_ARRAY)
		return rank1;
	#endif
	//
	#if defined(RANK_TWO_ARRAY)
		return rank1*rank2;
	#endif
	//
	#if defined(RANK_THREE_ARRAY)
		return 0;
	#endif
	//
	#if defined(RANK_FOUR_ARRAY)
		return 0;
	#endif
};
