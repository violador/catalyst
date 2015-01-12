//
//
//
/// @param [in] input A numerical data with same type of the array.
//
/// @brief Fills all the array elements with the given numerical data.
/// Only if it was previously initialized either by construction or
/// the array::create() member function. Otherwise nothing is done.
//
/// @return None.
//
/// @note Notice that array::set_all() member function behaves just like the
/// assignment operator between an array object and a given numerical data.
//
inline void set_all(data_type input)
{
	OMP_STATIC_LOOP_POLICY
	for(INIT_ITER(i, 0); i < data_length(); ++i)
	{
		data[i] = input;
	}
};
