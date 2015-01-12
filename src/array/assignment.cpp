//
//
//
/// @param [in] input A previously initialized array of the same rank order.
//
/// @brief The operator @c = applied between two array objects, copy all the
/// elements (from right to left), only if both arrays were previously
/// initialized either by construction or the array::create() member function.
/// Otherwise nothing is done.
//
/// @return None.
//
inline void operator =(const array_type &input)
{
	OMP_STATIC_LOOP_POLICY
	for(INIT_ITER(i, 0); i < data_length() && i < input.data_length(); ++i)
	{
		data[i] = input.data[i];
	}
	copy_ranks(input);
};
//
//
//
/// @param [in] input A previously temporary array of the same rank order.
//
/// @brief The operator @c = applied between an array object and a temporary
/// array object, moves all the temporary content to the non-temporary one,
/// with no size requirements or previous initialization being needed. This
/// operation is an indirect way to initialize an uninitialized object instead
/// invoking the array::create() member function, though the main usage must
/// be higher efficiency to pass content between objects. The temporary array
/// is left in an uninitialized state and the operation is carried out by the
/// master thread only.
//
/// @return None.
//
/// @note Please notice that if given an uninitialized temporary object, the
/// content of the current array, if any, will be lost and it will assume an
/// uninitialized state.
//
inline void operator =(array_type &&input)
{
	#pragma omp master
	{
		delete[] data;
		copy_data_members(input);
		input.reset_data_members();
	}
};
//
//
//
/// @param [in] input A numerical data with same type of the array.
//
/// @brief The operator @c = applied between an array object and a numerical
/// data, fills all the current elements, only if the array was previously
/// initialized either by construction or the array::create() member function.
/// Otherwise nothing is done.
//
/// @return None.
//
inline void operator =(data_type input)
{
	OMP_STATIC_LOOP_POLICY
	for(INIT_ITER(i, 0); i < data_length(); ++i)
	{
		data[i] = input;
	}
};
