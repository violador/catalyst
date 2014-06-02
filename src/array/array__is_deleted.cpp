//
//
//
/// @brief Checks if the current array is deleted,
///        i.e. not allocated.
//
/// @return @c true if it is deleted, and @c false
///         otherwise.
//
inline bool is_deleted() const
{
	return (data == NULL);
};
