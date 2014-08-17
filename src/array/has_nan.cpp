//
//
//
/// @brief Checks if at least one element of the current array is a @c nan,
///        i.e. not-a-number, such as @c '0/0' or @c 'std::sqrt(-1)'.
//
/// @return @c true if it has one or more @c nan, @c false otherwise.
//
inline bool has_nan() const
{
	auto check = [](int iter)
	{
		return std::isnan(iter);
	};
	switch(data != NULL)
	{
		case  true: return std::any_of(data, data_end(), check);
		case false: return false;
	}
};
