//
//
//
/// @brief If the current array was previously initialized, either by the
///        constructor or the array::create() member function, array::sum()
///        returns the summation of all the elements. Or returns zero,
///        otherwise.
//
/// @return A numerical data of the same type of the current array.
//
inline data_type sum()
{
	switch(data != NULL)
	{
		case  true: return std::accumulate(data, data_end(), data_type(0.0));
		case false: return 0.0;
	}
};
