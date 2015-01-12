//
//
//
/// @param [in] size1 The first rank length for a rank one array.
//
/// @brief Attempts to allocate memory for the current array, if it
/// was not previously initialized by construction, and sets all the
/// new elements to zero by default. The array::is_ready() member
/// function can check afterwards if the creation was properly done.
//
/// @return None.
//
#if CURRENT_RANK == 1
	void create(unsigned int size1)
	{
		if(!is_ready())
		{
			rank1 = size1;
			if(!init_data())
			{
				reset_data_members();
			}
		}
	};
#endif
//
//
//
#if CURRENT_RANK == 2
	void create(unsigned int size1, unsigned int size2)
	{
		if(!is_ready())
		{
			rank1 = size1;
			rank2 = size2;
			if(!init_data())
			{
				reset_data_members();
			}
		}
	};
#endif
