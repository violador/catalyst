//
//
//
/// @param [in] input A previously initialized array with the same rank order.
//
/// @brief The operator @c + applied between two arrays of same rank, add up
/// each element and returns the resulting array by move assignment or move
/// construction. Only if both arrays were previously initialized either by
/// construction or the array::create() member function. Otherwise nothing is
/// done.
//
/// @return An array with the same rank order.
//
array_type operator +(const array_type &input)
{
	array_type output;
	output.init_as(this);
	OMP_STATIC_LOOP_POLICY
	for(INIT_ITER(i, 0); i < output.data_length() && i < input.data_length(); ++i)
	{
		output.data[i] = data[i] + input.data[i];
	}
	return output;
};
//
//
//
/// @param [in] input A previously initialized array with the same rank order.
//
/// @brief The operator @c += applied between two arrays of same rank, add up
/// each element. Only if both arrays were previously initialized either by
/// construction or the array::create() member function. Otherwise nothing is
/// done.
//
/// @return None.
//
inline void operator +=(const array_type &input)
{
	OMP_STATIC_LOOP_POLICY
	for(INIT_ITER(i, 0); i < data_length() && i < input.data_length(); ++i)
	{
		data[i] += input.data[i];
	}
};
//
//
//
/// @param [in] input A numerical data of the same type of the array.
//
/// @brief The operator @c + applied between an array and a number (of the
/// same data type), add up the number to each element and returns the resulting
/// array by move assignment or move construction. Only if the array was previously
/// initialized either by construction or the array::create() member function.
/// Otherwise nothing is done.
//
/// @return An array with the same rank order.
//
array_type operator +(data_type input)
{
	array_type output;
	output.init_as(this);
	OMP_STATIC_LOOP_POLICY
	for(INIT_ITER(i, 0); i < output.data_length(); ++i)
	{
		output.data[i] = data[i] + input;
	}
	return output;
};
//
//
//
/// @param [in] input A numerical data of the same type of the array.
//
/// @brief The operator @c += applied between an array and a number (of the
/// same data type), add up the number to each element. Only if the array was
/// previously initialized either by construction or the array::create() member
/// function. Otherwise nothing is done.
//
/// @return None.
//
inline void operator +=(data_type input)
{
	OMP_STATIC_LOOP_POLICY
	for(INIT_ITER(i, 0); i < data_length(); ++i)
	{
		data[i] += input;
	}
};
