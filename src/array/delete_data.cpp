//
//
//
/// @brief A help function to deallocate the current memory and to set
///        zero the rank's lengths.
//
/// @return @c EXIT_SUCCESS.
//
inline int delete_data()
{
	delete[] data;
	data = NULL;
	#if defined(RANK_ONE_ARRAY)
		rank1 = 0;
	#endif
	//
	#if defined(RANK_TWO_ARRAY)
		rank1 = rank2 = 0;
	#endif
	//
	#if defined(RANK_THREE_ARRAY)
		rank1 = rank2 = rank3 = 0;
	#endif
	//
	#if defined(RANK_FOUR_ARRAY)
		rank1 = rank2 = rank3 = rank4 = 0;
	#endif
	return EXIT_SUCCESS;
};
