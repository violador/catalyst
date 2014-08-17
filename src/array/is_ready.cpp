//
//
//
/// @brief Checks if the current array was previously 
///        initialized either by the constructor or by 
///        the array::create() member function. Case
///        not, there is no memory allocated and the 
///        array must be initialized first.
//
/// @return @true if ready or @false, otherwise.
//
inline bool is_ready() const
{
	return (data != NULL);
};
