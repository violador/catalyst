//
//
//
/// @param [in] input A previously declared rank one array.
//
/// @brief The operator @c = is used to copy the elements from the @c input array
///        to the current one. Only if the arrays were previously initialized by the
///        constructor or the array::create() member function, and their size are
///        the same. Otherwise nothing is done. The operation is carried out by the
///        master thread.
//
/// @return None.
//
inline void init_as(const array_type *input)
{
	#if CURRENT_RANK == 1
	{
		rank1 = input -> rank1;
		init_data();
	}
	#elif CURRENT_RANK == 2
	{
		rank1 = input -> rank1;
		rank2 = input -> rank2;
		init_data();
	}
	#elif CURRENT_RANK == 3
	{
		rank1 = input -> rank1;
		rank2 = input -> rank2;
		rank3 = input -> rank3;
		init_data();
	}
	#elif CURRENT_RANK == 4
	{
		rank1 = input -> rank1;
		rank2 = input -> rank2;
		rank3 = input -> rank3;
		rank4 = input -> rank4;
		init_data();
	}
	#else
	{
		return;
	}
	#endif
};
