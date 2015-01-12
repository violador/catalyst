//
//
//
/// @brief Reset the array setting all the elements to zero. Only if it was
/// previously initialized either by construction or the array::create()
/// member function. Otherwise nothing is done. The array::is_null() member
/// might be used to check if the array was properly reset.
//
/// @return None.
//
/// @note Notice that array::set_zero() member function behaves just like the
/// assignment operator between an array object and zero.
//
inline void set_zero()
{
	OMP_STATIC_LOOP_POLICY
	for(INIT_ITER(i, 0); i < data_length(); ++i)
	{
		data[i] = data_type(0.0);
	}
};
