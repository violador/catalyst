//
//
//
/// @brief Checks if the current array is a square and not deleted 2D array.
//
/// @return @c true if @c rank1 @c == @c rank2, and @c false
///         otherwise.
//
inline bool is_square() const
{
	return (is_2d() && (!is_deleted()) && rank1 == rank2);
};
