//
//
//
/// @brief Checks if all the elements of the current array are zero.
//
/// @return @c true if all the elements are zero or if the current
///         array was not previously initialized by the constructor
///         or the array::create() member funtion. @c false
///         otherwise.
//
inline bool is_null() const
{
	auto check = [](int iter)
	{
		return (iter == 0.0);
	};
	switch(data != NULL)
	{
		case  true: return std::all_of(data, data_end(), check);
		case false: return true;
	}
};
