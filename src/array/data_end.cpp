//
//
//
/// @brief A private memeber function used to check the pointer pointing
/// the end of the array. The pointer for the begin is the @c data or @c
/// data[0] itself.
//
/// @return A pointer with the same type of the current array.
//
constexpr data_type *data_end() const
{
	return data + data_length();
};
