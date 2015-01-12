//
//
//
/// @param [in] i The @c i element of the first rank in a rank one array.
//
/// @brief Returns the @f$ A_{i} @f$ element, checking if it is inside the
/// array length. To avoid the bounds check-in, the operator @c '( )' can
/// be used instead.
//
/// @return A numerical data of the same type of the current array.
//
#if CURRENT_RANK == 1
	data_type get(unsigned int i)
	{
		if(offset(i) < data_length())
		{
			return data[offset(i)];
		}
		else
		{
			return data_type(0.0);
		}
	};
#endif
//
//
//
#if CURRENT_RANK == 2
	data_type get(unsigned int i, unsigned int j)
	{
		if(offset(i, j) < data_length())
		{
			return data[offset(i, j)];
		}
		else
		{
			return data_type(0.0);
		}
	};
#endif
