//
//
//
/// @brief Calculates the trace of the current rank two array if it
/// is square and was previously initialized either by construction
/// or the array::create() member function. Otherwise returns zero.
//
/// @return A numerical data with the same type of the array.
//
data_type trace()
{
	data_type trace(0.0);
	if(is_square())
	{
		for(INIT_ITER(i, 1); i <= data_length(); ++i)
		{
			trace += data[offset(i, i)];
		}
	}
	return trace;
};
