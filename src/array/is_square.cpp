//
//
//
/// @brief Checks if the current array is a rank two square array.
//
/// @return @c true if it is square and @c false otherwise.
//
constexpr bool is_square() const
{
	return bool(first_rank() == second_rank());
};
