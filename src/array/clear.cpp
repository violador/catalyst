//
//
//
/// @brief If the current array was previously initialized either by construction
/// or the array::create() member function, the array::clear() deallocates the
/// memory used and resets the object state for an uninitialized one. From this
/// point on, array::create() should be invoked to reallocate memory, before any
/// attempt to use it again. The operation is carried out by the master thread
/// only.
//
/// @return None.
//
/// @note Please notice, this member function does not replace the class destructor
/// that will be called by default at the end of the scope. Its main usage is to
/// free memory when desired.
//
inline void clear()
{
	#pragma omp master
	{
		delete[] data;
		reset_data_members();
	}
};
