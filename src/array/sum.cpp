//
//
//
/// @brief If the current array was previously initialized, either by
/// construction or the array::create() member function, array::sum()
/// returns the summation of all the elements. Otherwise, returns zero.
//
/// @return A numerical data with the same type of the current array.
//
inline data_type sum()
{
	return std::accumulate(data, data_end(), data_type(0.0));
};
