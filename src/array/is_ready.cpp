//
//
//
/// @brief Checks if the current array was previously initialized
/// either by construction or the array::create() member function.
//
/// @return @c true if it is ready and @c false otherwise.
//
constexpr bool is_ready() const
{
	return bool(data != NULL);
};
