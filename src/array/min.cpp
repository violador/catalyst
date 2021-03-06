//
//
//
/// @brief If the current array was previously initialized, either by the
///        constructor or the array::create() member function, array::min()
///        returns the smaller element. Or returns zero, otherwise.
//
/// @return A numerical data of the same type of the current array.
//
inline data_type min() const
{
	switch(is_ready())
	{
		case  true: return *std::min_element(data, data_end());
		case false: return data_type(0.0);
	}
};
