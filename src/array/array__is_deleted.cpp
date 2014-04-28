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
	return ((data1 == NULL) && (data2 == NULL)
	                        && (data3 == NULL)
							&& (data4 == NULL));
};
