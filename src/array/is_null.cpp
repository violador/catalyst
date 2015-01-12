//
//
//
/// @brief Checks if all the elements are zero.
//
/// @return @c true if all the elements are zero or if the current array
/// was not previously initialized by construction or the array::create()
/// member funtion. And returns @c false otherwise.
//
bool is_null() const
{
	auto check = [](int iter)
	{
		return (iter == 0.0);
	};
	return std::all_of(data, data_end(), check);
};
