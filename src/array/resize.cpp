//
//
//
/// @param [in] size The first rank length.
//
/// @brief This member function will resize the current object if
///        it was previously properly initialized either by the
///        constructor or by the array::create() member function.
//
/// @return @c EXIT_SUCCESS or @c EXIT_FAILURE.
//
inline void resize(unsigned int new_size)
{
	delete_data();
	// FINISH HERE! SET UP THE RANKS FIRST!
	init_data(new_size);
};
