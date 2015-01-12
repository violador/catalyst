//
//
//
/// @brief Checks if at least one element of the current array is
/// a not-a-number.
//
/// @return @c true if there is a not-a-number, or @c false otherwise.
//
bool has_nan() const
{
	if(is_ready())
	{
		auto check = [](int iter)
		{
			return std::isnan(iter);
		};
		return std::any_of(data, data_end(), check);
	}
	else
	{
		return false;
	}
};
