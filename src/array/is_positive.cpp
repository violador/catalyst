//
//
//
/// @brief Checks if all the elements are positive, including zero. Only
/// if the current array was previously initialized either by construction
/// or the array::create().
//
/// @return @c true if all the elements are positive, and @c false otherwise.
//
bool is_positive() const
{
	if(is_ready())
	{
		auto check = [](int iter)
		{
			return (iter >= 0.0);
		};
		return std::all_of(data, data_end(), check);
	}
	else
	{
		return false;
	}
};
