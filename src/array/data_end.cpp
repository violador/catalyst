//
//
//
/// @brief A help function used to check the pointer pointing the
//         end of the array. The pointer for the begin is the @c
//         data or @c data[0] itself.
//
/// @return A pointer of the same type of the current array.
//
inline data_type *data_end() const
{
	#if defined(RANK_ONE_ARRAY)
		return data + rank1;
	#endif
	//
	#if defined(RANK_TWO_ARRAY)
		return data + (rank1*rank2);
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
