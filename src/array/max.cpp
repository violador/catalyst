//
//
//
/// @brief If the current array was previously initialized, either by the
///        constructor or the array::create() member function, array::max()
///        returns the higher element. Or returns zero, otherwise.
//
/// @return A numerical data of the same type of the current array.
//
inline data_type max() const
{
	switch(is_ready())
	{
		case  true: return *std::max_element(data, data_end());
		case false: return data_type(0.0);
	}
};
