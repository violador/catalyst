//
//
//
/// @brief Checks if all the elements of the current array are positive,
///        including zero as an unsigned number, i.e. nonegative.
//
/// @return @c true if all the elements are positive, @c false otherwise,
///         or if the current array was not previously initialized by the
///         constructor or the array::create() member funtion.
//
inline bool is_positive() const
{
	auto check = [](int iter)
	{
		return (iter >= 0.0);
	};
	switch(data != NULL)
	{
		case  true: return std::all_of(data, data_end(), check);
		case false: return false;
	}
};
