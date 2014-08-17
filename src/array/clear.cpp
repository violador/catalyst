//
//
//
/// @brief If the current array was previously initialized,
///        either by the constructor or the array::create()
///        member function, array::clear() will delete the
///        current data, deallocating the memory used. After
///        this, to use the object again, array::create()
///        should be invoked first, to reallocate the memory.
//
/// @return @c EXIT_SUCCESS or @c EXIT_FAILURE.
//
/// @note Please notice, this member function does not replace
///       the class destructor that is going to be called by
///       default in the right moment. The main usage of this
///       function is to free memory when desired.
//
inline int clear()
{
	switch(data != NULL)
	{
		case  true: return delete_data();
		case false: return EXIT_FAILURE;
	}
};
