//
//
//
/// @brief A private member function to set zero all the
/// current rank's length and the @c data pointer to @c
/// NULL. Its usage is highly recommended just after any
/// delete or move operation of the data members.
//
/// @return None.
//
inline void clear_internals()
{
	#if CURRENT_RANK == 1
	{
		data = NULL;
		rank1 = 0;
	}
	#elif CURRENT_RANK == 2
	{
		data = NULL;
		rank1 = rank2 = 0;
	}
	#elif CURRENT_RANK == 3
	{
		data = NULL;
		rank1 = rank2 = rank3 = 0;
	}
	#elif CURRENT_RANK == 4
	{
		data = NULL;
		rank1 = rank2 = rank3 = rank4 = 0;
	}
	#else
	{
		data = NULL;
	}
	#endif
};
