//
//
//
/// @brief Checks the current object ID.
//
/// @return A non-negative integer if the
///         array is not deleted, and zero
///         otherwise.
//
inline unsigned int check_id()
{
	switch(not_deleted())
	{
		case false: return 0;
		case  true: return data_id;
	}
};
