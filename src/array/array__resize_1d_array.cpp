//
//
//
inline int resize_1d_array(const unsigned int &new_size)
{
	switch(rank1 == new_size)
	{
		case false:
		{
			clear();
			init_data(new_size);
			return EXIT_SUCCESS;
		}
		case true:
		{
			return EXIT_FAILURE;
		}
	}
};
