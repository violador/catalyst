//
//
//
/// @brief Checks the current object ID.
//
/// @return A non-negative integer if the
///         array is not deleted, and zero
///         otherwise.
//
inline unsigned int check_array_id()
{
	switch(!is_deleted())
	{
		case false: return 0; break;
		case  true: return array_id; break;
	}
};
