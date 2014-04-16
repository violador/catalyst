//
//
//
/// @brief Checks if the current array is a square and not deleted 2D array.
//
/// @return @c true if @c sizeof_row @c == @c sizeof_column, and @c false
///         otherwise.
//
inline bool is_square()
{
	return ((sizeof_row == sizeof_column) && (!is_deleted()) && is_2d());
};
