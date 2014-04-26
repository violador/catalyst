//
//
//
/// @brief Checks if the current array is deleted.
//
/// @return @c true if it is deleted, and @c false
///         otherwise.
//
inline bool is_deleted() const
{
	return ((user_1d_array == NULL) && (user_2d_array == NULL)
	                                && (user_3d_array == NULL)
									&& (user_4d_array == NULL));
};
